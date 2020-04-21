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

//���ȵ�λm���Ƕȵ�λrad

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
	double air_speed; //��֪�����ٷ����Ļ�����ʲô�����Ž��ϵķ����ܲ�����
	double v_body;//��֪���ܲ���ֱ���յ������ٶ�
	geometry_msgs / Eigen::Quaterniond attitude_qv;  //��Ԫ��
	bool Drop(float x,float y,float z);
}plane;

bool plane::Drop(float x,float y, float z)
{
	#define g=9.8;
	const float delay_t = 0.5;
	float tx = x - pos.x-v.x_sp*delay_t;
	float ty = y - pos.y-v.y_sp*delay_t;
	float tz = z - pos.z-v.z_sp*delay_t;//����任���õ��б���Էɻ���λʸ��

	pos.z += v.z_sp * delay_t;
	 
	float h_t = sqrt(2 * pos.z / g);
	float s_x = v.x_sp * h_t;
	float s_y = v.y_sp * h_t;

	float d_val=sqrt((tx-s_x)^2+(ty-s_y)^2);

	if (d_val<=3)
		return true;
	return 0;
//	else
		//return Drop(x, y, z);��֪����ͨ���ص�������������ٽ�����Ϣ���ⲿ���ú�����
		
}