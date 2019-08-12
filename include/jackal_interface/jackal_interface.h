#ifndef JACKAL_INTERFACE_JACKAL_INTERFACE_H_INCLUDED
#define JACKAL_INTERFACE_JACKAL_INTERFACE_H_INCLUDED

#include <ros/ros.h>
#include <autoware_msgs/VehicleCmd.h>
#include <geometry_msgs/Twist.h>

class JackalInterface
{
public:
    JackalInterface(ros::NodeHandle nh,ros::NodeHandle pnh);
    ~JackalInterface();
private:
    ros::NodeHandle nh_;
    ros::NodeHandle pnh_;
    ros::Publisher twist_cmd_pub_;
    ros::Subscriber vehicle_cmd_sub_;
    void vehicleCommandCallback(const autoware_msgs::VehicleCmd::ConstPtr msg);
};

#endif  //JACKAL_INTERFACE_JACKAL_INTERFACE_H_INCLUDED