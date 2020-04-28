#include "def.h"
bool myplane::Drop(float x, float y, float z)
{
	const float g = 9.8;
	const float r = 3;//综合效率和准确率调整
	const float delay_t = 0.5;
	//x,y,z是以机身为原点的ENU系
	float tx = x -  v.x_sp * delay_t;
	float ty = y - v.y_sp * delay_t;
	float tz = z  - v.z_sp * delay_t;//坐标变换，得到靶标相对飞机的位矢在ENU坐标系下。
	pos.z += v.z_sp * delay_t;
	//如果x,y,z是绝对的ENU系
	/*
	float tx = x -pos.x-  v.x_sp * delay_t;
	float ty = y - pos.y-v.y_sp * delay_t;
	*/
	//attitude[2] +=ang_r.pitch_r*delay_t;//抬头是负，pitch的加速度比较小，如果考虑上误差可能有点大，看试验结果调整
	//attitude[3] += ang_r.yaw_r * delay_t;//正东为0，逆时针为正
	float t1 = v.z_sp / g;//用飞机的竖直速度分量代水瓶竖直速度，可能有误差，之后再改进,上面是用俯仰角和偏航角的思路
	float h = pos.z + v.z_sp * v.z_sp / (2 * g);
	float t_h = sqrt(2 * h / g);
	float s_x = v.x_sp * (t_h+t1);
	float s_y = v.y_sp * (t_h+t1);

	float d_val = sqrt((tx - s_x) * (tx - s_x) + (ty - s_y) * (ty - s_y));

	if (d_val <= r)
		return true;
	return 0;
	//	else
			//return Drop(x, y, z);不知道是通过回调函数解决还是再接收信息再外部调用函数。

}
