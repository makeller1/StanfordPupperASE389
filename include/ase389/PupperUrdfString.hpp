#ifndef PUPPER_URDF_HH_
#define PUPPER_URDF_HH_
// Note: used https://tomeko.net/online_tools/cpp_text_escape.php?lang=en to convert urdf to multi-line string 

// <?xml version="1.0" encoding="utf-8"?>
// <!-- =================================================================================== -->
// <!-- |    This document was autogenerated by xacro from pupper.urdf.xacro              | -->
// <!-- |    EDITING THIS FILE BY HAND IS NOT RECOMMENDED                                 | -->
// <!-- =================================================================================== -->

const char* pupper_urdf_string = 
"<robot name=\"pupper\">\n"
"  <!-- Connect the plugin -->\n"
"  <gazebo>\n"
"    <plugin filename=\"libpupper_plugin.so\" name=\"pupper_plugin\"/>\n"
"  </gazebo>\n"
"  <!-- TODO: Get the correct mass and inertia on the feet -->\n"
"  <!-- ++++++++++++++++ -->\n"
"  <!-- ROBOT START HERE -->\n"
"  <!-- ++++++++++++++++ -->\n"
"  <!-- Base link of the robot -->\n"
"  <link name=\"bottom_PCB\">\n"
"    <inertial>\n"
"      <mass value=\"0.0246155987687\"/>\n"
"      <inertia ixx=\"0.000161445031637\" ixy=\"0.0\" ixz=\"0.0\" iyy=\"1.7324369412e-05\" iyz=\"0.0\" izz=\"0.000178741870837\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Create Front bulkhead -->\n"
"  <link name=\"front_bulkhead\">\n"
"    <inertial>\n"
"      <mass value=\"0.010506396\"/>\n"
"      <inertia ixx=\"1.022692356e-05\" ixy=\"0.0\" ixz=\"0.0\" iyy=\"2.7748515648e-05\" iyz=\"0.0\" izz=\"3.1221326112e-05\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Join Front Bulkhead with Base -->\n"
"  <joint name=\"front_bulkhead_to_base\" type=\"fixed\">\n"
"    <parent link=\"bottom_PCB\"/>\n"
"    <child link=\"front_bulkhead\"/>\n"
"    <origin rpy=\"1.5707963268 0 0\" xyz=\"0.002 0.114 0.044\"/>\n"
"  </joint>\n"
"  <!-- Create Middle Bulkhead -->\n"
"  <link name=\"middle_bulkhead_front\">\n"
"    <inertial>\n"
"      <mass value=\"0.012366396\"/>\n"
"      <inertia ixx=\"8.554681632e-06\" ixy=\"0.0\" ixz=\"0.0\" iyy=\"1.897506528e-05\" iyz=\"0.0\" izz=\"2.7393755616e-05\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Join Middle Bulkhead to Base -->\n"
"  <joint name=\"middle_bulkhead_to_base_1\" type=\"fixed\">\n"
"    <parent link=\"bottom_PCB\"/>\n"
"    <child link=\"middle_bulkhead_front\"/>\n"
"    <origin rpy=\"1.5707963268 0 0\" xyz=\"0.002 0.114 0.044\"/>\n"
"  </joint>\n"
"  <!-- Create 2nd Middle Bulkhead -->\n"
"  <link name=\"middle_bulkhead_rear\">\n"
"    <inertial>\n"
"      <mass value=\"0.012373464\"/>\n"
"      <inertia ixx=\"8.15128632e-06\" ixy=\"0.0\" ixz=\"0.0\" iyy=\"1.5096884928e-05\" iyz=\"0.0\" izz=\"2.3080296576e-05\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Join 2nd Bulkhead to Base -->\n"
"  <joint name=\"middle_bulkhead_to_base_2\" type=\"fixed\">\n"
"    <parent link=\"bottom_PCB\"/>\n"
"    <child link=\"middle_bulkhead_rear\"/>\n"
"    <origin rpy=\"1.5707963268 0 0\" xyz=\"0.003 0.114 0.044\"/>\n"
"  </joint>\n"
"  <!-- Create back right shroud -->\n"
"  <link name=\"back_right_shroud\">\n"
"    <inertial>\n"
"      <mass value=\"0.0058404\"/>\n"
"      <inertia ixx=\"1.1398658832e-05\" ixy=\"0.0\" ixz=\"0.0\" iyy=\"7.916366832e-06\" iyz=\"0.0\" izz=\"3.977793396e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Connect back right shroud to body -->\n"
"  <joint name=\"right_shroud_to_base\" type=\"fixed\">\n"
"    <parent link=\"bottom_PCB\"/>\n"
"    <child link=\"back_right_shroud\"/>\n"
"    <origin rpy=\"1.5707963268 3.14159265359 0\" xyz=\"0.003 0.113 0.044\"/>\n"
"  </joint>\n"
"  <!-- Create back left shroud -->\n"
"  <link name=\"back_left_shroud\">\n"
"    <inertial>\n"
"      <mass value=\"0.0058404\"/>\n"
"      <inertia ixx=\"1.1398638744e-05\" ixy=\"0.0\" ixz=\"0.0\" iyy=\"7.916371296e-06\" iyz=\"0.0\" izz=\"3.97777368e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Join back left shroud to body -->\n"
"  <joint name=\"back_left_shroud_to_base\" type=\"fixed\">\n"
"    <parent link=\"bottom_PCB\"/>\n"
"    <child link=\"back_left_shroud\"/>\n"
"    <origin rpy=\"1.5707963268 3.14159265359 0\" xyz=\"0.003 0.113 0.044\"/>\n"
"  </joint>\n"
"  <!-- Create rear bulkhead -->\n"
"  <link name=\"rear_bulkhead\">\n"
"    <inertial>\n"
"      <mass value=\"0.012549792\"/>\n"
"      <inertia ixx=\"8.688962472e-06\" ixy=\"0.0\" ixz=\"0.0\" iyy=\"1.9400512752e-05\" iyz=\"-6.655824e-09\" izz=\"2.7950330112e-05\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Join rear bulkhead to body -->\n"
"  <joint name=\"rear_bulk_head_to_body\" type=\"fixed\">\n"
"    <parent link=\"bottom_PCB\"/>\n"
"    <child link=\"rear_bulkhead\"/>\n"
"    <origin rpy=\"1.5707963268 0 0\" xyz=\"0.003 0.113 0.044\"/>\n"
"  </joint>\n"
"  <!-- Create a bulk mass for the battery -->\n"
"  <link name=\"battery\">\n"
"    <inertial>\n"
"      <mass value=\"0.228\"/>\n"
"      <inertia ixx=\"6.796775e-05\" ixy=\"0\" ixz=\"0\" iyy=\"0.00013779275\" iyz=\"0\" izz=\"0.000116375\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Connect battery to body -->\n"
"  <joint name=\"battery_to_body\" type=\"fixed\">\n"
"    <parent link=\"bottom_PCB\"/>\n"
"    <child link=\"battery\"/>\n"
"    <origin xyz=\"0.002 0.03 0.02425\"/>\n"
"  </joint>\n"
"  <!-- Create top plate -->\n"
"  <link name=\"top_PCB\">\n"
"    <inertial>\n"
"      <mass value=\"0.0246155987687\"/>\n"
"      <inertia ixx=\"0.000161445031637\" ixy=\"0.0\" ixz=\"0.0\" iyy=\"1.7324369412e-05\" iyz=\"0.0\" izz=\"0.000178741870837\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Joint top plate to body -->\n"
"  <joint name=\"top_PCB_to_base\" type=\"fixed\">\n"
"    <parent link=\"bottom_PCB\"/>\n"
"    <child link=\"top_PCB\"/>\n"
"    <origin rpy=\"0 0 0\" xyz=\"0 0 0.088\"/>\n"
"  </joint>\n"
"  <link name=\"front_left_hub\">\n"
"    <inertial>\n"
"      <mass value=\"0.002639712\"/>\n"
"      <inertia ixx=\"5.41895748e-07\" ixy=\"0.0\" ixz=\"1.66169424e-07\" iyy=\"5.47751772e-07\" iyz=\"0.0\" izz=\"4.29932304e-07\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <link name=\"front_left_upper_link\">\n"
"    <inertial>\n"
"      <mass value=\"0.005135088\"/>\n"
"      <inertia ixx=\"5.2268046e-06\" ixy=\"5.830542e-08\" ixz=\"0.0\" iyy=\"3.56244684e-07\" iyz=\"0.0\" izz=\"4.920666084e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <link name=\"front_left_cover\">\n"
"    <inertial>\n"
"      <mass value=\"0.002386008\"/>\n"
"      <inertia ixx=\"1.588040844e-06\" ixy=\"6.3907368e-08\" ixz=\"2.604e-13\" iyy=\"3.68898264e-07\" iyz=\"-8.928e-12\" izz=\"1.42387278e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Connect the covering to the upper link -->\n"
"  <joint name=\"front_left_shroud_to_leg\" type=\"fixed\">\n"
"    <parent link=\"front_left_upper_link\"/>\n"
"    <child link=\"front_left_cover\"/>\n"
"    <origin rpy=\"3.14159265359 0 0\" xyz=\"0.007 0.085 0\"/>\n"
"  </joint>\n"
"  <link name=\"front_left_lower_link\">\n"
"    <inertial>\n"
"      <mass value=\"0.00489924\"/>\n"
"      <inertia ixx=\"6.752526888e-06\" ixy=\"-8.8765524e-08\" ixz=\"7.420284e-09\" iyy=\"1.62788688e-07\" iyz=\"2.50211292e-07\" izz=\"6.810224088e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Create the foot pad -->\n"
"  <link name=\"front_left_foot\">\n"
"    <inertial>\n"
"      <mass value=\"0.01\"/>\n"
"      <inertia ixx=\"3.61e-07\" ixy=\"0\" ixz=\"0\" iyy=\"3.61e-07\" iyz=\"0\" izz=\"3.61e-07\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Connect foot pad to lower link -->\n"
"  <joint name=\"front_left_foot_joint\" type=\"fixed\">\n"
"    <parent link=\"front_left_lower_link\"/>\n"
"    <child link=\"front_left_foot\"/>\n"
"    <origin rpy=\"1.5707963268 0 0.685398163398\" xyz=\"0 -0.11 0.009\"/>\n"
"  </joint>\n"
"  <!-- Create the motor -->\n"
"  <link name=\"front_left_hip\">\n"
"    <inertial>\n"
"      <mass value=\"0.12\"/>\n"
"      <inertia ixx=\"7.2e-6\" ixy=\"0\" ixz=\"0\" iyy=\"1.11e-5\" iyz=\"0\" izz=\"1.11e-5\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Rigidly attach to motor to it's parent -->\n"
"  <joint name=\"front_left_hip_fixed_joint\" type=\"fixed\">\n"
"    <parent link=\"bottom_PCB\"/>\n"
"    <child link=\"front_left_hip\"/>\n"
"    <origin rpy=\"-1.5707963268 0 0\" xyz=\"0.05 -0.105 0.044\"/>\n"
"  </joint>\n"
"  <!-- Attach the child link through a revolute joint -->\n"
"  <joint name=\"front_left_hip_joint\" type=\"revolute\">\n"
"    <parent link=\"front_left_hip\"/>\n"
"    <child link=\"front_left_hub\"/>\n"
"    <origin rpy=\"0 1.5707963268 0\" xyz=\"0 0 0.036\"/>\n"
"    <limit effort=\"1e6\" lower=\"-1e10\" upper=\"1e10\" velocity=\"1e6\"/>\n"
"    <dynamics damping=\"0.3\" friction=\"0.3\"/>\n"
"    <axis xyz=\"-1 0 0\"/>\n"
"  </joint>\n"
"  <!-- Create the motor -->\n"
"  <link name=\"front_left_shoulder\">\n"
"    <inertial>\n"
"      <mass value=\"0.12\"/>\n"
"      <inertia ixx=\"7.2e-6\" ixy=\"0\" ixz=\"0\" iyy=\"1.11e-5\" iyz=\"0\" izz=\"1.11e-5\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Rigidly attach to motor to it's parent -->\n"
"  <joint name=\"front_left_shoulder_fixed_joint\" type=\"fixed\">\n"
"    <parent link=\"front_left_hub\"/>\n"
"    <child link=\"front_left_shoulder\"/>\n"
"    <origin rpy=\"0 0 0\" xyz=\"0 0 0.005\"/>\n"
"  </joint>\n"
"  <!-- Attach the child link through a revolute joint -->\n"
"  <joint name=\"front_left_shoulder_joint\" type=\"revolute\">\n"
"    <parent link=\"front_left_shoulder\"/>\n"
"    <child link=\"front_left_upper_link\"/>\n"
"    <origin rpy=\"0 -1.5707963268 0\" xyz=\"0 0 0.022\"/>\n"
"    <limit effort=\"1e6\" lower=\"-1e10\" upper=\"1e10\" velocity=\"1e6\"/>\n"
"    <dynamics damping=\"0.3\" friction=\"0.3\"/>\n"
"    <axis xyz=\"1 0 0\"/>\n"
"  </joint>\n"
"  <!-- Create the motor -->\n"
"  <link name=\"front_left_elbow\">\n"
"    <inertial>\n"
"      <mass value=\"0.12\"/>\n"
"      <inertia ixx=\"7.2e-6\" ixy=\"0\" ixz=\"0\" iyy=\"1.11e-5\" iyz=\"0\" izz=\"1.11e-5\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Rigidly attach to motor to it's parent -->\n"
"  <joint name=\"front_left_elbow_fixed_joint\" type=\"fixed\">\n"
"    <parent link=\"front_left_upper_link\"/>\n"
"    <child link=\"front_left_elbow\"/>\n"
"    <origin rpy=\"0 1.5707963268 0\" xyz=\"0.023 0.082 0\"/>\n"
"  </joint>\n"
"  <!-- Attach the child link through a revolute joint -->\n"
"  <joint name=\"front_left_elbow_joint\" type=\"revolute\">\n"
"    <parent link=\"front_left_elbow\"/>\n"
"    <child link=\"front_left_lower_link\"/>\n"
"    <origin rpy=\"3.14159265359 3.14159265359 0\" xyz=\"0 0 -0.032\"/>\n"
"    <limit effort=\"1e6\" lower=\"-1e10\" upper=\"1e10\" velocity=\"1e6\"/>\n"
"    <dynamics damping=\"0.3\" friction=\"0.3\"/>\n"
"    <axis xyz=\"0 0 -1\"/>\n"
"  </joint>\n"
"  <link name=\"back_left_hub\">\n"
"    <inertial>\n"
"      <mass value=\"0.002639712\"/>\n"
"      <inertia ixx=\"5.41895748e-07\" ixy=\"0.0\" ixz=\"1.66169424e-07\" iyy=\"5.47751772e-07\" iyz=\"0.0\" izz=\"4.29932304e-07\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <link name=\"back_left_upper_link\">\n"
"    <inertial>\n"
"      <mass value=\"0.005135088\"/>\n"
"      <inertia ixx=\"5.2268046e-06\" ixy=\"5.830542e-08\" ixz=\"0.0\" iyy=\"3.56244684e-07\" iyz=\"0.0\" izz=\"4.920666084e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <link name=\"back_left_cover\">\n"
"    <inertial>\n"
"      <mass value=\"0.002386008\"/>\n"
"      <inertia ixx=\"1.588040844e-06\" ixy=\"6.3907368e-08\" ixz=\"2.604e-13\" iyy=\"3.68898264e-07\" iyz=\"-8.928e-12\" izz=\"1.42387278e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Connect the covering to the upper link -->\n"
"  <joint name=\"back_left_shroud_to_leg\" type=\"fixed\">\n"
"    <parent link=\"back_left_upper_link\"/>\n"
"    <child link=\"back_left_cover\"/>\n"
"    <origin rpy=\"3.14159265359 0 0\" xyz=\"0.007 0.085 0\"/>\n"
"  </joint>\n"
"  <link name=\"back_left_lower_link\">\n"
"    <inertial>\n"
"      <mass value=\"0.00489924\"/>\n"
"      <inertia ixx=\"6.752526888e-06\" ixy=\"-8.8765524e-08\" ixz=\"7.420284e-09\" iyy=\"1.62788688e-07\" iyz=\"2.50211292e-07\" izz=\"6.810224088e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Create the foot pad -->\n"
"  <link name=\"back_left_foot\">\n"
"    <inertial>\n"
"      <mass value=\"0.01\"/>\n"
"      <inertia ixx=\"3.61e-07\" ixy=\"0\" ixz=\"0\" iyy=\"3.61e-07\" iyz=\"0\" izz=\"3.61e-07\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Connect foot pad to lower link -->\n"
"  <joint name=\"back_left_foot_joint\" type=\"fixed\">\n"
"    <parent link=\"back_left_lower_link\"/>\n"
"    <child link=\"back_left_foot\"/>\n"
"    <origin rpy=\"1.5707963268 0 0.685398163398\" xyz=\"0 -0.11 0.009\"/>\n"
"  </joint>\n"
"  <!-- Create the motor -->\n"
"  <link name=\"back_left_hip\">\n"
"    <inertial>\n"
"      <mass value=\"0.12\"/>\n"
"      <inertia ixx=\"7.2e-6\" ixy=\"0\" ixz=\"0\" iyy=\"1.11e-5\" iyz=\"0\" izz=\"1.11e-5\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Rigidly attach to motor to it's parent -->\n"
"  <joint name=\"back_left_hip_fixed_joint\" type=\"fixed\">\n"
"    <parent link=\"bottom_PCB\"/>\n"
"    <child link=\"back_left_hip\"/>\n"
"    <origin rpy=\"-1.5707963268 0 0\" xyz=\"0.05 0.095 0.044\"/>\n"
"  </joint>\n"
"  <!-- Attach the child link through a revolute joint -->\n"
"  <joint name=\"back_left_hip_joint\" type=\"revolute\">\n"
"    <parent link=\"back_left_hip\"/>\n"
"    <child link=\"back_left_hub\"/>\n"
"    <origin rpy=\"0 1.5707963268 0\" xyz=\"0 0 0.036\"/>\n"
"    <limit effort=\"1e6\" lower=\"-1e10\" upper=\"1e10\" velocity=\"1e6\"/>\n"
"    <dynamics damping=\"0.3\" friction=\"0.3\"/>\n"
"    <axis xyz=\"-1 0 0\"/>\n"
"  </joint>\n"
"  <!-- Create the motor -->\n"
"  <link name=\"back_left_shoulder\">\n"
"    <inertial>\n"
"      <mass value=\"0.12\"/>\n"
"      <inertia ixx=\"7.2e-6\" ixy=\"0\" ixz=\"0\" iyy=\"1.11e-5\" iyz=\"0\" izz=\"1.11e-5\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Rigidly attach to motor to it's parent -->\n"
"  <joint name=\"back_left_shoulder_fixed_joint\" type=\"fixed\">\n"
"    <parent link=\"back_left_hub\"/>\n"
"    <child link=\"back_left_shoulder\"/>\n"
"    <origin rpy=\"0 0 0\" xyz=\"0 0 0.005\"/>\n"
"  </joint>\n"
"  <!-- Attach the child link through a revolute joint -->\n"
"  <joint name=\"back_left_shoulder_joint\" type=\"revolute\">\n"
"    <parent link=\"back_left_shoulder\"/>\n"
"    <child link=\"back_left_upper_link\"/>\n"
"    <origin rpy=\"0 -1.5707963268 0\" xyz=\"0 0 0.022\"/>\n"
"    <limit effort=\"1e6\" lower=\"-1e10\" upper=\"1e10\" velocity=\"1e6\"/>\n"
"    <dynamics damping=\"0.3\" friction=\"0.3\"/>\n"
"    <axis xyz=\"1 0 0\"/>\n"
"  </joint>\n"
"  <!-- Create the motor -->\n"
"  <link name=\"back_left_elbow\">\n"
"    <inertial>\n"
"      <mass value=\"0.12\"/>\n"
"      <inertia ixx=\"7.2e-6\" ixy=\"0\" ixz=\"0\" iyy=\"1.11e-5\" iyz=\"0\" izz=\"1.11e-5\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Rigidly attach to motor to it's parent -->\n"
"  <joint name=\"back_left_elbow_fixed_joint\" type=\"fixed\">\n"
"    <parent link=\"back_left_upper_link\"/>\n"
"    <child link=\"back_left_elbow\"/>\n"
"    <origin rpy=\"0 1.5707963268 0\" xyz=\"0.023 0.082 0\"/>\n"
"  </joint>\n"
"  <!-- Attach the child link through a revolute joint -->\n"
"  <joint name=\"back_left_elbow_joint\" type=\"revolute\">\n"
"    <parent link=\"back_left_elbow\"/>\n"
"    <child link=\"back_left_lower_link\"/>\n"
"    <origin rpy=\"3.14159265359 3.14159265359 0\" xyz=\"0 0 -0.032\"/>\n"
"    <limit effort=\"1e6\" lower=\"-1e10\" upper=\"1e10\" velocity=\"1e6\"/>\n"
"    <dynamics damping=\"0.3\" friction=\"0.3\"/>\n"
"    <axis xyz=\"0 0 -1\"/>\n"
"  </joint>\n"
"  <link name=\"front_right_hub\">\n"
"    <inertial>\n"
"      <mass value=\"0.002639712\"/>\n"
"      <inertia ixx=\"5.41895748e-07\" ixy=\"0.0\" ixz=\"-1.66169424e-07\" iyy=\"5.47751772e-07\" iyz=\"0.0\" izz=\"4.29932304e-07\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <link name=\"front_right_upper_link\">\n"
"    <inertial>\n"
"      <mass value=\"0.005135088\"/>\n"
"      <inertia ixx=\"5.2268046e-06\" ixy=\"5.830542e-08\" ixz=\"0.0\" iyy=\"3.56244684e-07\" iyz=\"0.0\" izz=\"4.920666084e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <link name=\"front_right_cover\">\n"
"    <inertial>\n"
"      <mass value=\"0.002386008\"/>\n"
"      <inertia ixx=\"1.588040844e-06\" ixy=\"6.3907368e-08\" ixz=\"2.604e-13\" iyy=\"3.68898264e-07\" iyz=\"-8.928e-12\" izz=\"1.42387278e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Connect the covering to the upper link -->\n"
"  <joint name=\"front_right_shroud_to_leg\" type=\"fixed\">\n"
"    <parent link=\"front_right_upper_link\"/>\n"
"    <child link=\"front_right_cover\"/>\n"
"    <origin rpy=\"3.14159265359 0 0\" xyz=\"0.007 0.085 0\"/>\n"
"  </joint>\n"
"  <link name=\"front_right_lower_link\">\n"
"    <inertial>\n"
"      <mass value=\"0.00489924\"/>\n"
"      <inertia ixx=\"6.752526888e-06\" ixy=\"-8.8765524e-08\" ixz=\"-7.420284e-09\" iyy=\"1.62788688e-07\" iyz=\"-2.50211292e-07\" izz=\"6.810224088e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Create the foot pad -->\n"
"  <link name=\"front_right_foot\">\n"
"    <inertial>\n"
"      <mass value=\"0.01\"/>\n"
"      <inertia ixx=\"3.61e-07\" ixy=\"0\" ixz=\"0\" iyy=\"3.61e-07\" iyz=\"0\" izz=\"3.61e-07\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Connect foot pad to lower link -->\n"
"  <joint name=\"front_right_foot_joint\" type=\"fixed\">\n"
"    <parent link=\"front_right_lower_link\"/>\n"
"    <child link=\"front_right_foot\"/>\n"
"    <origin rpy=\"1.5707963268 0 0.685398163398\" xyz=\"0 -0.11 -0.009\"/>\n"
"  </joint>\n"
"  <!-- Create the motor -->\n"
"  <link name=\"front_right_hip\">\n"
"    <inertial>\n"
"      <mass value=\"0.12\"/>\n"
"      <inertia ixx=\"7.2e-6\" ixy=\"0\" ixz=\"0\" iyy=\"1.11e-5\" iyz=\"0\" izz=\"1.11e-5\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Rigidly attach to motor to it's parent -->\n"
"  <joint name=\"front_right_hip_fixed_joint\" type=\"fixed\">\n"
"    <parent link=\"bottom_PCB\"/>\n"
"    <child link=\"front_right_hip\"/>\n"
"    <origin rpy=\"-1.5707963268 0 0\" xyz=\"-0.045 -0.105 0.044\"/>\n"
"  </joint>\n"
"  <!-- Attach the child link through a revolute joint -->\n"
"  <joint name=\"front_right_hip_joint\" type=\"revolute\">\n"
"    <parent link=\"front_right_hip\"/>\n"
"    <child link=\"front_right_hub\"/>\n"
"    <origin rpy=\"0 1.5707963268 0\" xyz=\"0 0 0.036\"/>\n"
"    <limit effort=\"1e6\" lower=\"-1e10\" upper=\"1e10\" velocity=\"1e6\"/>\n"
"    <dynamics damping=\"0.3\" friction=\"0.3\"/>\n"
"    <axis xyz=\"-1 0 0\"/>\n"
"  </joint>\n"
"  <!-- Create the motor -->\n"
"  <link name=\"front_right_shoulder\">\n"
"    <inertial>\n"
"      <mass value=\"0.12\"/>\n"
"      <inertia ixx=\"7.2e-6\" ixy=\"0\" ixz=\"0\" iyy=\"1.11e-5\" iyz=\"0\" izz=\"1.11e-5\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Rigidly attach to motor to it's parent -->\n"
"  <joint name=\"front_right_shoulder_fixed_joint\" type=\"fixed\">\n"
"    <parent link=\"front_right_hub\"/>\n"
"    <child link=\"front_right_shoulder\"/>\n"
"    <origin rpy=\"0 0 0\" xyz=\"0 0 -0.005\"/>\n"
"  </joint>\n"
"  <!-- Attach the child link through a revolute joint -->\n"
"  <joint name=\"front_right_shoulder_joint\" type=\"revolute\">\n"
"    <parent link=\"front_right_shoulder\"/>\n"
"    <child link=\"front_right_upper_link\"/>\n"
"    <origin rpy=\"0 1.5707963268 0\" xyz=\"0 0 -0.02\"/>\n"
"    <limit effort=\"1e6\" lower=\"-1e10\" upper=\"1e10\" velocity=\"1e6\"/>\n"
"    <dynamics damping=\"0.3\" friction=\"0.3\"/>\n"
"    <axis xyz=\"1 0 0\"/>\n"
"  </joint>\n"
"  <!-- Create the motor -->\n"
"  <link name=\"front_right_elbow\">\n"
"    <inertial>\n"
"      <mass value=\"0.12\"/>\n"
"      <inertia ixx=\"7.2e-6\" ixy=\"0\" ixz=\"0\" iyy=\"1.11e-5\" iyz=\"0\" izz=\"1.11e-5\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Rigidly attach to motor to it's parent -->\n"
"  <joint name=\"front_right_elbow_fixed_joint\" type=\"fixed\">\n"
"    <parent link=\"front_right_upper_link\"/>\n"
"    <child link=\"front_right_elbow\"/>\n"
"    <origin rpy=\"0 1.5707963268 0\" xyz=\"0.023 0.082 0\"/>\n"
"  </joint>\n"
"  <!-- Attach the child link through a revolute joint -->\n"
"  <joint name=\"front_right_elbow_joint\" type=\"revolute\">\n"
"    <parent link=\"front_right_elbow\"/>\n"
"    <child link=\"front_right_lower_link\"/>\n"
"    <origin rpy=\"3.14159265359 0 0\" xyz=\"0 0 -0.032\"/>\n"
"    <limit effort=\"1e6\" lower=\"-1e10\" upper=\"1e10\" velocity=\"1e6\"/>\n"
"    <dynamics damping=\"0.3\" friction=\"0.3\"/>\n"
"    <axis xyz=\"0 0 1\"/>\n"
"  </joint>\n"
"  <link name=\"back_right_hub\">\n"
"    <inertial>\n"
"      <mass value=\"0.002639712\"/>\n"
"      <inertia ixx=\"5.41895748e-07\" ixy=\"0.0\" ixz=\"-1.66169424e-07\" iyy=\"5.47751772e-07\" iyz=\"0.0\" izz=\"4.29932304e-07\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <link name=\"back_right_upper_link\">\n"
"    <inertial>\n"
"      <mass value=\"0.005135088\"/>\n"
"      <inertia ixx=\"5.2268046e-06\" ixy=\"5.830542e-08\" ixz=\"0.0\" iyy=\"3.56244684e-07\" iyz=\"0.0\" izz=\"4.920666084e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <link name=\"back_right_cover\">\n"
"    <inertial>\n"
"      <mass value=\"0.002386008\"/>\n"
"      <inertia ixx=\"1.588040844e-06\" ixy=\"6.3907368e-08\" ixz=\"2.604e-13\" iyy=\"3.68898264e-07\" iyz=\"-8.928e-12\" izz=\"1.42387278e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Connect the covering to the upper link -->\n"
"  <joint name=\"back_right_shroud_to_leg\" type=\"fixed\">\n"
"    <parent link=\"back_right_upper_link\"/>\n"
"    <child link=\"back_right_cover\"/>\n"
"    <origin rpy=\"3.14159265359 0 0\" xyz=\"0.007 0.085 0\"/>\n"
"  </joint>\n"
"  <link name=\"back_right_lower_link\">\n"
"    <inertial>\n"
"      <mass value=\"0.00489924\"/>\n"
"      <inertia ixx=\"6.752526888e-06\" ixy=\"-8.8765524e-08\" ixz=\"-7.420284e-09\" iyy=\"1.62788688e-07\" iyz=\"-2.50211292e-07\" izz=\"6.810224088e-06\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Create the foot pad -->\n"
"  <link name=\"back_right_foot\">\n"
"    <inertial>\n"
"      <mass value=\"0.01\"/>\n"
"      <inertia ixx=\"3.61e-07\" ixy=\"0\" ixz=\"0\" iyy=\"3.61e-07\" iyz=\"0\" izz=\"3.61e-07\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Connect foot pad to lower link -->\n"
"  <joint name=\"back_right_foot_joint\" type=\"fixed\">\n"
"    <parent link=\"back_right_lower_link\"/>\n"
"    <child link=\"back_right_foot\"/>\n"
"    <origin rpy=\"1.5707963268 0 0.685398163398\" xyz=\"0 -0.11 -0.009\"/>\n"
"  </joint>\n"
"  <!-- Create the motor -->\n"
"  <link name=\"back_right_hip\">\n"
"    <inertial>\n"
"      <mass value=\"0.12\"/>\n"
"      <inertia ixx=\"7.2e-6\" ixy=\"0\" ixz=\"0\" iyy=\"1.11e-5\" iyz=\"0\" izz=\"1.11e-5\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Rigidly attach to motor to it's parent -->\n"
"  <joint name=\"back_right_hip_fixed_joint\" type=\"fixed\">\n"
"    <parent link=\"bottom_PCB\"/>\n"
"    <child link=\"back_right_hip\"/>\n"
"    <origin rpy=\"-1.5707963268 0 0\" xyz=\"-0.045 0.095 0.044\"/>\n"
"  </joint>\n"
"  <!-- Attach the child link through a revolute joint -->\n"
"  <joint name=\"back_right_hip_joint\" type=\"revolute\">\n"
"    <parent link=\"back_right_hip\"/>\n"
"    <child link=\"back_right_hub\"/>\n"
"    <origin rpy=\"0 1.5707963268 0\" xyz=\"0 0 0.036\"/>\n"
"    <limit effort=\"1e6\" lower=\"-1e10\" upper=\"1e10\" velocity=\"1e6\"/>\n"
"    <dynamics damping=\"0.3\" friction=\"0.3\"/>\n"
"    <axis xyz=\"-1 0 0\"/>\n"
"  </joint>\n"
"  <!-- Create the motor -->\n"
"  <link name=\"back_right_shoulder\">\n"
"    <inertial>\n"
"      <mass value=\"0.12\"/>\n"
"      <inertia ixx=\"7.2e-6\" ixy=\"0\" ixz=\"0\" iyy=\"1.11e-5\" iyz=\"0\" izz=\"1.11e-5\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Rigidly attach to motor to it's parent -->\n"
"  <joint name=\"back_right_shoulder_fixed_joint\" type=\"fixed\">\n"
"    <parent link=\"back_right_hub\"/>\n"
"    <child link=\"back_right_shoulder\"/>\n"
"    <origin rpy=\"0 0 0\" xyz=\"0 0 -0.005\"/>\n"
"  </joint>\n"
"  <!-- Attach the child link through a revolute joint -->\n"
"  <joint name=\"back_right_shoulder_joint\" type=\"revolute\">\n"
"    <parent link=\"back_right_shoulder\"/>\n"
"    <child link=\"back_right_upper_link\"/>\n"
"    <origin rpy=\"0 1.5707963268 0\" xyz=\"0 0 -0.02\"/>\n"
"    <limit effort=\"1e6\" lower=\"-1e10\" upper=\"1e10\" velocity=\"1e6\"/>\n"
"    <dynamics damping=\"0.3\" friction=\"0.3\"/>\n"
"    <axis xyz=\"1 0 0\"/>\n"
"  </joint>\n"
"  <!-- Create the motor -->\n"
"  <link name=\"back_right_elbow\">\n"
"    <inertial>\n"
"      <mass value=\"0.12\"/>\n"
"      <inertia ixx=\"7.2e-6\" ixy=\"0\" ixz=\"0\" iyy=\"1.11e-5\" iyz=\"0\" izz=\"1.11e-5\"/>\n"
"    </inertial>\n"
"  </link>\n"
"  <!-- Rigidly attach to motor to it's parent -->\n"
"  <joint name=\"back_right_elbow_fixed_joint\" type=\"fixed\">\n"
"    <parent link=\"back_right_upper_link\"/>\n"
"    <child link=\"back_right_elbow\"/>\n"
"    <origin rpy=\"0 1.5707963268 0\" xyz=\"0.023 0.082 0\"/>\n"
"  </joint>\n"
"  <!-- Attach the child link through a revolute joint -->\n"
"  <joint name=\"back_right_elbow_joint\" type=\"revolute\">\n"
"    <parent link=\"back_right_elbow\"/>\n"
"    <child link=\"back_right_lower_link\"/>\n"
"    <origin rpy=\"3.14159265359 0 0\" xyz=\"0 0 -0.032\"/>\n"
"    <limit effort=\"1e6\" lower=\"-1e10\" upper=\"1e10\" velocity=\"1e6\"/>\n"
"    <dynamics damping=\"0.3\" friction=\"0.3\"/>\n"
"    <axis xyz=\"0 0 1\"/>\n"
"  </joint>\n"
"</robot>";

#endif