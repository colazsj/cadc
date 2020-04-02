#include "def.h"

struct Subscriber
{
	ros::Subscriber pose_cov;
	ros::Subscriber pose;
	ros::Subscriber odom;
	ros::Subscriber v_local;
	ros::Subscriber v_body;
	ros::Subscriber v_body_cov;
	ros::Subscriber att;
}sub;

void posInit(const std_msgs::String::ConstPtr& msg)
{
	plane.pos.x = msg->pose.position.x;
	plane.pos.y = msg->pose.position.y;
	plane.pos.z = msg->pose.position.z;
}



void v_localInit(const std_msgs::String::ConstPtr& msg)
{
	plane.v.x_sp = msg->twist.linear.x;
	plane.v.y_sp = msg->twist.linear.y;
	plane.v.z_sp = msg->twist.linear.z;
}

void v_bodyInit(const std_msgs::String::ConstPtr& msg)
{
	//因为不知道它发的是什么东西，可能是机体速度，先打出来看看。也不知道它的data是什么东西
	ROS_INFO("node_b is receiving [%s]", msg->data.c_str());
}

void att_cb(const sensor_msgs::Imu::ConstPtr& msg)
{
	 plane.attitude_qv = Quaterniond(msg->orientation.w, msg->orientation.x, msg->orientation.y, msg->orientation.z);
	 //保存四元数，未处理,不知道这个赋值函数能不能用

	plane.ang_r.roll_r = msg->angular_velocity.x;
	plane.ang_r.pitch_r = msg->angular_velocity.x;
	plane.ang_r.yaw_r = msg->angular_velocity.x;
}

/*void v_body_covInit(const std_msgs::String::ConstPtr& msg)
{
}
void pos_covInit(const std_msgs::String::ConstPtr& msg)
{
	//赋值
}
void odomInit(const std_msgs::String::ConstPtr& msg)
{

}*/

int main(int argc, char** argv)
{
	ros::init(argc, argv, "subscibe");
	ros::NodeHandle a;
	sub.pose = a.subscribe("pose", 10, posInit);
	sub.att = a.subscribe("/mavros/imu/data", 10, att_cb);
	sub.v_local = a.subscribe("velocity_local", 10, v_localInit);
	sub.v_body = a.subscribe("velocity_body", 10, v_bodyInit);
	sub.pose_cov = a.subscribe("pose_cov", 10, pos_covInit);
	sub.v_body_cov = a.subscribe("velocity_body_cov", 10, v_body_covInit);
	sub.odom = a.subscribe("odom", 10, odomInit);
	ros::spin();
	return 0;
}