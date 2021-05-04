#ifndef PUPPER_CONTROLLER_HH_
#define PUPPER_CONTROLLER_HH_

#include <vector>
#include <array>
#include <string>
#include <cstring>
#include <unordered_map>

#include "osqp.h"
#include "rbdl/rbdl.h"
#include "eigen3/Eigen/Dense"
#include "ase389/WBCTask.hpp"

#define ROBOT_NUM_JOINTS 12
#define NUM_JOINTS 18   // 12 motors plus 6 floating base joints
#define NUM_Q 19        // 12 motors plus 3 xyz plus 4 quaternion, refer to: https://rbdl.github.io/df/dbe/joint_description.html

// To make the code a little more readable
typedef RigidBodyDynamics::Math::MatrixNd Matrix;
typedef RigidBodyDynamics::Math::VectorNd Vector;
typedef RigidBodyDynamics::Math::Quaternion Quat;

class PupperWBC{
public:
    // Constructor
    PupperWBC();

    // Take in the current robot data
    void updateController(const std::array<float, ROBOT_NUM_JOINTS>& joint_angles, 
                          const std::array<float, ROBOT_NUM_JOINTS>& joint_velocities,
                          const Eigen::Quaternion<float>& body_quaternion,
                          const std::array<bool, 4>& feet_in_contact);

    // Add a task to the robot's task list
    void addTask(unsigned priority, std::string name, Task* task);

    // Load the Pupper model from a URDF
    void Load(std::string filename);

    // Get the torque command fulfilling the current tasks
    std::array<float, 12> calculateOutputTorque();

// private:
    // The Pupper model for RBDL
    RigidBodyDynamics::Model Pupper_;
    // Pupper constraints struct for RBDL
    RigidBodyDynamics::ConstraintSet pup_constraints_;

    // Retrieve the body COM Jacobian
    Matrix getBodyJacobian_(std::string body_id);

    // Retrieve the task Jacobian for specific task
    Matrix getTaskJacobian_(std::string task_name);
    Matrix getTaskJacobian_(unsigned priority);

    // Initialize RBDL constraints 
    void initConstraintSets_();

    // Retrieve the contact Jacobian for the active contacts
    Matrix getContactJacobian_();

    // Store the robot state
    Vector joint_angles_;        // joint angles in radians
    Vector joint_velocities_;    // joint velocities in rad/s
    Quat   robot_orientation_;   // robot orientation from IMU (Quaternion)
    Matrix Jc_;                  // contact Jacobian
    Matrix massMat_;             // mass matrix
    Vector b_g_;                 // coriolis plus gravity
    std::array<bool, 4> feet_in_contact_;                   // Feet in contact (boolean array: [back left, back right, front left, front right])

    // Control torques in Nm
    Vector control_torques_;

    // Body ids of lower links 
    uint back_left_lower_link_id_;
    uint back_right_lower_link_id_;
    uint front_left_lower_link_id_;
    uint front_right_lower_link_id_;

    // Map of robot tasks organized by name
    std::vector<Task*> robot_tasks_;
    std::unordered_map<std::string, unsigned> task_indices_;

    // OSQP Solver
    std::unique_ptr<OSQPSettings> QP_settings_;
    std::unique_ptr<OSQPData> QP_data_;
    void convertEigenToCSC_(const Matrix &P, std::vector<c_float> &P_x, std::vector<c_int> &P_p, std::vector<c_int> &P_i);
    void formQP(Matrix &P, Vector &q, Matrix &A, Vector &l, Vector &u);
    Vector solveQP(int n, int m, Matrix  &P, c_float *q, Matrix  &A, c_float *lb, c_float *ub);
};

#endif
