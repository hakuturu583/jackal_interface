#include <jackal_interface/jackal_interface.h>

JackalInterface::JackalInterface(ros::NodeHandle nh,ros::NodeHandle pnh)
{
    nh_ = nh;
    pnh_ = pnh;
}

JackalInterface::~JackalInterface()
{

}

void JackalInterface::vehicleCommandCallback(const autoware_msgs::VehicleCmd::ConstPtr msg)
{

}