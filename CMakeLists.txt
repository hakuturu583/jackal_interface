cmake_minimum_required(VERSION 2.8.3)
project(jackal_interface)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  autoware_msgs
  jackal_control
  jackal_description
  jackal_gazebo
  jackal_msgs
  jackal_viz
  roscpp
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES jackal_interface
#  CATKIN_DEPENDS autoware_msgs jackal_control jackal_description jackal_gazebo jackal_msgs jackal_simulator jackal_viz roscpp
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(jackal_interface_node src/jackal_interface_node.cpp src/jackal_interface.cpp)
target_link_libraries(jackal_interface_node ${catkin_LIBRARIES})
add_dependencies(jackal_interface_node ${catkin_EXPORTED_TARGETS})

# install executables/libs
install(TARGETS jackal_interface_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# install headers
install(DIRECTORY include
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

install(DIRECTORY launch xacro config world
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
        USE_SOURCE_PERMISSIONS)