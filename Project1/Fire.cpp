#include "def.h"
bool plane::Drop(float x, float y, float z)
{
	const float g = 9.8;
	const float r = 3;
	const float delay_t = 0.5;
	float tx = x - pos.x - v.x_sp * delay_t;
	float ty = y - pos.y - v.y_sp * delay_t;
	float tz = z - pos.z - v.z_sp * delay_t;//����任���õ��б���Էɻ���λʸ��

	pos.z += v.z_sp * delay_t;

	float h_t = sqrt(2 * pos.z / g);
	float s_x = v.x_sp * h_t;
	float s_y = v.y_sp * h_t;

	float d_val = sqrt((tx - s_x) * (tx - s_x) + (ty - s_y) * (ty - s_y));

	if (d_val <= r)
		return true;
	return 0;
	//	else
			//return Drop(x, y, z);��֪����ͨ���ص�������������ٽ�����Ϣ���ⲿ���ú�����

}
