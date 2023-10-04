#include <ros/ros.h>
#include <net_pkg/newwork.h>

void MsgCallback(const net_pkg::newwork::ConstPtr& msg);

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sub_node");
    ros::NodeHandle n;

    ros::Subscriber subscriber_msg;
    subscriber_msg=n.subscribe("msg", 1000, MsgCallback);

    ros::Rate loop_rate(60);


    while(ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;    
}

void MsgCallback(const net_pkg::newwork::ConstPtr& msg)
{
    ROS_INFO("(pc 1) %s", msg->String.c_str());
}