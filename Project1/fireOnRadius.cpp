#include "def.h"
bool myplane::Drop2(float x, float y, float z)
{
	const float g = 9.8;
	const float r = 3;//综合效率和准确率调整
	const float delay_t = 0.5;
	const float pi = 3.1415926;
	//x,y,z是以机身为原点的ENU系
	float tx = x - v.x_sp * delay_t;
	float ty = y - v.y_sp * delay_t;
	float tz = z - v.z_sp * delay_t;//坐标变换，得到靶标相对飞机的位矢在ENU坐标系下。
	pos.z += v.z_sp * delay_t;
	 //在落点在3m圆内判断为真的前提下（在一定范围内都会返回真，选最佳的投弹时机，与缩小判断的r范围比较看哪个准确率高），加强判断落点是否在垂直于飞机航向的直径上以保证落点有足够大的活动空间不会偏离圆心太多

	//attitude[2] +=ang_r.pitch_r*delay_t;//抬头是负，pitch的加速度比较小，如果考虑上误差可能有点大，看试验结果调整
	//attitude[3] += ang_r.yaw_r * delay_t;//正东为0，逆时针为正
	float t1 = v.z_sp / g;//用飞机的竖直速度分量代水瓶竖直速度，可能有误差，之后再改进,上面是用俯仰角和偏航角的思路
	//float h = pos.z + v.z_sp * v.z_sp / (2 * g);/有向上分速度的时候
	float t_h = sqrt(v.z_sp * v.z_sp + 2 * g * pos.z) / g;
	float s_x = v.x_sp * (t_h + t1);
	float s_y = v.y_sp * (t_h + t1);

	float d_val = sqrt((tx - s_x) * (tx - s_x) + (ty - s_y) * (ty - s_y));

	if (d_val <= r)
	{
		float a = s_x - tx;
		float b = s_y - ty;
		if (b / a *tan(plane.attitude[2])== (-1))
			return true;
		else return 0;
	}
		
	return 0;
	//均衡时间分，因为如果大家都没投中那时间一点点分也是可以分出高下的，如果时间到达一定时候就直接丢弃重物立即返航。
}