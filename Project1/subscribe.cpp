#include "def.h"

struct Subscriber
{
	ros::Subscriber pose;
	ros::Subscriber v_local;
	ros::Subscriber v_body;
	ros::Subscriber airspeed;
	ros::Subscriber att;
}sub;

void posInit(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
	plane.pos.x = msg->pose.position.x;
	plane.pos.y = msg->pose.position.y;
	plane.pos.z = msg->pose.position.z;
}



void v_localInit(const geometry_msgs::TwistStamped::ConstPtr& msg)
{
	plane.v.x_sp = msg->twist.linear.x;
	plane.v.y_sp = msg->twist.linear.y;
	plane.v.z_sp = msg->twist.linear.z;
}//这里接收到了角速度好像不太行，线速度还是能用的

void v_bodyInit(const geometry_msgs::TwistStamped::ConstPtr& msg)
{
	//  接收机体坐标系下机身向前的速度。
	plane.v_body = msg->twist.linear.x;
}

Eigen::Vector3d quaternion_to_euler(const Eigen::Quaterniond& q)
{
	float quat[4];
	quat[0] = q.w();
	quat[1] = q.x();
	quat[2] = q.y();
	quat[3] = q.z();

	Eigen::Vector3d ans;
	ans[0] = atan2(2.0 * (quat[3] * quat[2] + quat[0] * quat[1]), 1.0 - 2.0 * (quat[1] * quat[1] + quat[2] * quat[2]));
	ans[1] = asin(2.0 * (quat[2] * quat[0] - quat[3] * quat[1]));
	ans[2] = atan2(2.0 * (quat[3] * quat[0] + quat[1] * quat[2]), 1.0 - 2.0 * (quat[2] * quat[2] + quat[3] * quat[3]));
	return ans;
}

void att_cb(const sensor_msgs::Imu::ConstPtr& msg)
{
	plane.attitude_qv = Eigen::Quaterniond(msg->orientation.w, msg->orientation.x, msg->orientation.y, msg->orientation.z);

	Eigen::Vector3d euler_fcu = quaternion_to_euler(plane.attitude_qv);

	plane.attitude[0] = euler_fcu[0];
	plane.attitude[1] = euler_fcu[1];
	plane.attitude[2] = euler_fcu[2];
	//角度顺序同RPY
	plane.ang_r.roll_r = msg->angular_velocity.x;
	plane.ang_r.pitch_r = msg->angular_velocity.x;
	plane.ang_r.yaw_r = msg->angular_velocity.x;
}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "subscibe");
	ros::NodeHandle a;
	sub.pose = a.subscribe("pose", 10, posInit);
	sub.att = a.subscribe("/mavros/imu/data", 10, att_cb);
	sub.v_local = a.subscribe("velocity_local", 10, v_localInit);
	sub.v_body = a.subscribe("velocity_body", 10, v_bodyInit);
	ros::spin();
	return 0;
}