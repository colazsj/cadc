#include <iostream>
#include <vector>
#include <ros/ros.h>
#include <ros/package.h>
#include "std_msgs/String.h"
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
using namespace std;

//长度单位m，角度单位rad

struct position {
	double x, y, z;
};


struct velocity {
	double x_sp, y_sp, z_sp; 
};

struct ang_rate
{
	double roll_r, pitch_r, yaw_r;
};

struct plane {
	position pos;
	velocity v;
	ang_rate ang_r;
	double air_speed; //不知道空速发布的话题是什么
	double v_body;//不知道能不能直接收到机体速度
	geometry_msgs / Quaternion attitude_qv;  //四元数
}plane;
