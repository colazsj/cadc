#include "def.h"

struct Subscriber
{
	ros::Subscriber pose_cov;
	ros::Subscriber pose;
	ros::Subscriber odom;
	ros::Subscriber v_local;
	ros::Subscriber v_body;
	ros::Subscriber v_body_cov;
}sub;

void posInit(const std_msgs::String::ConstPtr& msg)
{
	plane.pos.x = msg->pose.position.x;
	mocap_ned_pose.position.y = msg->pose.position.y;
	mocap_ned_msg.pose.position.z = msg->pose.position.z;
	mocap_ned_msg.pose.orientation.x = msg->pose.orientation.x;
	mocap_ned_msg.pose.orientation.y = msg->pose.orientation.y;
	mocap_ned_msg.pose.orientation.z = msg->pose.orientation.z;
	mocap_ned_msg.pose.orientation.w = msg->pose.orientation.w;
	 //¸³Öµ
}

void pos_covInit(const std_msgs::String::ConstPtr& msg)
{
	//¸³Öµ
}

void odomInit(const std_msgs::String::ConstPtr& msg)
{
}

void v_localInit(const std_msgs::String::ConstPtr& msg)
{
}

void v_bodyInit(const std_msgs::String::ConstPtr& msg)
{
}

void v_body_covInit(const std_msgs::String::ConstPtr& msg)
{
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "subscibe");
	ros::NodeHandle a;
	sub.pose = a.subscribe("pose", 10, posInit);
	sub.pose_cov = a.subscribe("pose_cov", 10, pos_covInit);
	sub.v_local = a.subscribe("velocity_local", 10, v_localInit);
	sub.v_body = a.subscribe("velocity_body", 10, v_bodyInit);
	sub.v_body_cov = a.subscribe("velocity_body_cov", 10, v_body_covInit);
	sub.odom = a.subscribe("odom", 10, odomInit);
	ros::spin();
	return 0;
}