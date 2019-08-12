#include <jackal_interface/jackal_interface.h>

JackalInterface::JackalInterface(ros::NodeHandle nh,ros::NodeHandle pnh)
{
    nh_ = nh;
    pnh_ = pnh;
    twist_cmd_pub_ = nh_.advertise<geometry_msgs::Twist>("/jackal_velocity_controller/cmd_vel",1);
    vehicle_cmd_sub_ = nh_.subscribe("/vehicle_cmd",1,&JackalInterface::vehicleCommandCallback,this);
}

JackalInterface::~JackalInterface()
{

}

void JackalInterface::vehicleCommandCallback(const autoware_msgs::VehicleCmd::ConstPtr msg)
{
    twist_cmd_pub_.publish(msg->twist_cmd.twist);
}