// Headers in ROS
#include <ros/ros.h>

// Headers in this package
#include <jackal_interface/jackal_interface.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "jackal_interface_node");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");
    JackalInterface interface(nh,pnh);
    ros::spin();
    return 0;
}