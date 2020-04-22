#include <iostream>
#include <vector>
#include <ros/ros.h>
#include <ros/package.h>
#include "std_msgs/String.h"
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include "Eigen/Eigen"
#include <cmath>
using namespace Eigen;
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
	double v_body;//不知道能不能直接收到机体速度,机身坐标系下的话题得到的x是飞机向前的速度，但考虑到会有偏移，可能不太准，先用三维速度，如果后面发现面对标靶时机身坐标系更方便再改
	geometry_msgs / Eigen::Quaterniond attitude_qv;  //四元数
	bool Drop(float x,float y,float z);
}plane;

bool plane::Drop(float x,float y, float z)
{
	#define g=9.8;
	const float delay_t = 0.5;
	float tx = x - pos.x-v.x_sp*delay_t;
	float ty = y - pos.y-v.y_sp*delay_t;
	float tz = z - pos.z-v.z_sp*delay_t;//坐标变换，得到靶标相对飞机的位矢。

	pos.z += v.z_sp * delay_t;
	 
	float h_t = sqrt(2 * pos.z / g);
	float s_x = v.x_sp * h_t;
	float s_y = v.y_sp * h_t;

	float d_val=sqrt((tx-s_x)^2+(ty-s_y)^2);

	if (d_val<=3)
		return true;
	return 0;
//	else
		//return Drop(x, y, z);不知道是通过回调函数解决还是再接收信息再外部调用函数。
		
}
