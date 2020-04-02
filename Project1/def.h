#include <iostream>
#include <vector>
#include <ros/ros.h>
#include <ros/package.h>
#include "std_msgs/String.h"
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
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
	double air_speed; //��֪�����ٷ����Ļ�����ʲô
	double v_body;//��֪���ܲ���ֱ���յ������ٶ�
	geometry_msgs / Quaternion attitude_qv;  //��Ԫ��
}plane;
