#ifndef _DEF_
#define _DEF_
#include <math.h>
#include <string>
#include <vector>
#include <iostream>
#include <pthread.h>
#include <thread>
#include <chrono>
#include <boost/thread/mutex.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <ros/ros.h>
#include <ros/package.h>
#include <yaml-cpp/yaml.h>
#include <image_transport/image_transport.h>  
#include <cv_bridge/cv_bridge.h>  
#include <sensor_msgs/image_encodings.h>
#include <prometheus_msgs/DetectionInfo.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml.hpp>
#include "std_msgs/String.h"
#include "kcftracker.hpp"
#include <sstream>
#include <cmath>
#include <sensor_msgs/Imu.h>
#include <eigen3/Eigen/Eigen>
#include <mavros_msgs/VFR_HUD.h>
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

struct myplane {
	position pos;
	velocity v;
	ang_rate ang_r;
	double air_speed; //得到的似乎是机身坐标系下的飞机向前的空速，可以用来判断是否失速
	double v_body;//机身坐标系下的话题得到的x是飞机向前的速度，但考虑到会有偏移，可能不太准，先用三维速度，如果后面发现面对标靶时机身坐标系更方便再改
	Eigen::Quaterniond attitude_qv;  //四元数
	double attitude[3];
	bool Drop(float x,float y,float z);
	bool Drop2(float x, float y, float z)
}plane;


#endif