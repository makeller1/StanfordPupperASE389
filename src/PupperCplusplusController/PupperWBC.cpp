#include <iostream>
#include "ase389/PupperWBC.hpp"
#include "rbdl/addons/urdfreader/urdfreader.h"
#include "ase389/PupperUrdfString.hpp"

using std::vector;
using std::array;
using std::string;
using std::cout;
using std::endl;

using namespace RigidBodyDynamics;
using namespace RigidBodyDynamics::Math;

static Eigen::IOFormat f(3);

// Constructor
PupperWBC::PupperWBC(){
    joint_angles_     = VectorNd::Zero(NUM_JOINTS);
    joint_velocities_ = VectorNd::Zero(NUM_JOINTS);
    joint_torques_    = VectorNd::Zero(NUM_JOINTS);
    
}

void PupperWBC::updateController(const array<float, NUM_JOINTS>& joint_angles, 
                                 const array<float, NUM_JOINTS>& joint_velocities,
                                 const array<float, NUM_JOINTS>& joint_torques)
{
    for (int i = 0; i < NUM_JOINTS; i++){
        joint_angles_[i]     = joint_angles[i];
        joint_velocities_[i] = joint_velocities[i];
        joint_torques_[i]    = joint_torques[i];
    }
}

void PupperWBC::addTask(unsigned priority, string name, Task* T){
    if (robot_tasks_.size() <= priority){
        robot_tasks_.resize(priority + 1);
    }
    robot_tasks_[priority] = T;
    task_indices_[name] = priority;
}

void PupperWBC::Load(string filename){
    // Load the model
    //RigidBodyDynamics::Addons::URDFReadFromFile(filename.c_str(), &Pupper_, true, true);
    RigidBodyDynamics::Addons::URDFReadFromString(pupper_urdf_string, &Pupper_, true, false);

    // Summarize model characteristics
    printf("Loaded model with %d DOFs\n", Pupper_.dof_count);
    printf("*\tQ Count:   \t%d\n", Pupper_.q_size);
    printf("*\tQdot Count:\t%d\n", Pupper_.qdot_size);
    printf("*\tBody Count:\t%zd\n", Pupper_.mBodies.size());
    printf("*\tJoint Count:\t%zd\n", Pupper_.mJoints.size());
    printf("*\tBody Names:\n");
    for (int i = 0; i < Pupper_.mBodies.size(); i++)
        cout << "*\t|----" << i << "\t=> " << Pupper_.GetBodyName(i) << endl;

    //Test
    array<bool, 4> feet_in_contact = {1,1,1,1};
    setContacts(feet_in_contact);
}

// Set rbdl model contact constraints
void PupperWBC::setContacts(const array<bool, 4> feet_in_contact){
    
    //feet_in_contact is a boolean mask with the order:
    // [back left, back right, front left, front right]
    if (feet_in_contact[0] == true){
        //const char* body_name = "back_lower_left_link";
        uint back_lower_left_link_id = Pupper_.GetBodyId("back_lower_left_link");
        uint back_lower_right_link_id = Pupper_.GetBodyId("back_lower_right_link");
        uint front_lower_left_link_id = Pupper_.GetBodyId("front_lower_left_link");
        uint front_lower_right_link_id = Pupper_.GetBodyId("front_lower_right_link");

        const Math::Vector3d body_contact_point_left(0.0, -.11, 0.0095);
        const Math::Vector3d body_contact_point_right(0.0, -.11, -0.0095);
        // Contact normal direction in base coordinates
        const Math::Vector3d world_normal(0.0, 0.0, 1.0); // TODO: modify based on orientation data
        const char* constraint_name = "lower_left_contact";
        
        pup_constraints_.AddContactConstraint(back_lower_left_link_id, body_contact_point_left, world_normal, "back_left_contact");
        pup_constraints_.AddContactConstraint(back_lower_right_link_id, body_contact_point_right, world_normal, "back_right_contact");
        pup_constraints_.AddContactConstraint(front_lower_left_link_id, body_contact_point_left, world_normal, "front_left_contact");
        pup_constraints_.AddContactConstraint(front_lower_right_link_id, body_contact_point_right, world_normal, "front_right_contact");
    }
    cout << "CONTACTS ADDED" << endl;
    pup_constraints_.Bind(Pupper_); // Not sure if we need to bind for what we're doing 
    // Test
    MatrixNd J_constraints = Eigen::MatrixXd::Zero(4, Pupper_.qdot_size);
    CalcConstraintsJacobian(Pupper_, joint_angles_, pup_constraints_, J_constraints);
    cout << "Jacobian for constraints is: \n" << J_constraints.format(f) << endl;
}

// Retrieve body Jacobian
MatrixNd PupperWBC::getBodyJacobian_(string body_id) {
    // Create output
    MatrixNd J = Eigen::MatrixXd::Zero(6, Pupper_.qdot_size);
    printf("\n\nBody Jacobian Test:\n");

    // Fill the Jacobian matrix
    ConstraintSet s;
    CalcBodySpatialJacobian(Pupper_, joint_angles_, Pupper_.GetBodyId(body_id.c_str()), J, true);
    cout << "Jacobian for \"" << body_id << "\" is: \n" << J.transpose().format(f) << endl;

    return J;
}


// Get the derivative of a task with respect to the joint angles
MatrixNd PupperWBC::getTaskJacobian_(unsigned priority){
    Task* T = robot_tasks_[priority];
    MatrixNd Jt;

    if (T->type == "body_pos"){
        MatrixNd Jb = getBodyJacobian_(T->body_id);

        // Create selection matrix to zero out rows we don't care about
        MatrixNd U  = MatrixNd::Zero(3,3);
        for (int i = 0; i < 3; i++){
            U(i, i) = T->active_targets[i];
        }

        Jt = U * Jb.topRows(3);

        cout << "Position Only: " << endl;
        cout << Jt.transpose() << endl;

    }else if (T->type == "body_ori"){
        MatrixNd Jb = getBodyJacobian_(T->body_id);

        // In general we care about all 4 parts of a quaternion, so 
        // there's no selection matrix for this one
        Jt = Jb.bottomRows(3);
        cout << "Orientation only: \n" << Jt.transpose() << endl;

    }else if(T->type == "joint_pos"){
        Jt = MatrixNd::Zero(Pupper_.qdot_size, Pupper_.qdot_size);

        // For joint position Jacobians the value is either 1 or zero
        for (int i = 0; i < T->active_targets.size(); i++){
            Jt(i, i) = T->active_targets[i];
        }

        cout << "Joint position Jacobian: \n" << Jt.format(f) << endl;
    }else{
        throw(std::runtime_error("Unrecognized WBC Task format"));
    }

    return Jt;
}

// Overloaded version of getTaskJacobian_
MatrixNd PupperWBC::getTaskJacobian_(std::string task_name){
    unsigned index = task_indices_.at(task_name);
    getTaskJacobian_(index);
}

array<float, 12> PupperWBC::calculateOutputTorque(){
    for (int i = 0; i < robot_tasks_.size(); i++){
        getTaskJacobian_(i);
    }

    return array<float,12>();
}
