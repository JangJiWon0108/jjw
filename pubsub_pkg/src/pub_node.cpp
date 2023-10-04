#include <ros/ros.h>
#include <net_pkg/newwork.h>
#include <string>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pub_node");
    ros::NodeHandle n;

    
    ros::Publisher publisher_msg=n.advertise<net_pkg::newwork>("msg", 1000);

    ros::Rate loop_rate(60);

    std::string user_input;

    while(ros::ok())
    {
        std::cout << "enter : ";
        std::cin >> user_input;

        net_pkg::newwork msg;
        msg.String=user_input;

        publisher_msg.publish(msg);

        /*
        ROS_INFO("(send data) Int8 = %d", tutorial_msg.Int8);
        ROS_INFO("(send data) Float32 = %.2f", tutorial_msg.Float32);
        ROS_INFO("(send data) String = %s", tutorial_msg.String.c_str());
        ROS_INFO("(send data) Time = %f", tutorial_msg.Time.toSec());
        ROS_INFO("(send data) Duration = %f", tutorial_msg.Duration.toSec());     
        */   

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
