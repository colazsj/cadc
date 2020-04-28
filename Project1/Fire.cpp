#include "def.h"
bool myplane::Drop(float x, float y, float z)
{
	const float g = 9.8;
	const float r = 3;//�ۺ�Ч�ʺ�׼ȷ�ʵ���
	const float delay_t = 0.5;
	//x,y,z���Ի���Ϊԭ���ENUϵ
	float tx = x -  v.x_sp * delay_t;
	float ty = y - v.y_sp * delay_t;
	float tz = z  - v.z_sp * delay_t;//����任���õ��б���Էɻ���λʸ��ENU����ϵ�¡�
	pos.z += v.z_sp * delay_t;
	//���x,y,z�Ǿ��Ե�ENUϵ
	/*
	float tx = x -pos.x-  v.x_sp * delay_t;
	float ty = y - pos.y-v.y_sp * delay_t;
	*/
	//attitude[2] +=ang_r.pitch_r*delay_t;//̧ͷ�Ǹ���pitch�ļ��ٶȱȽ�С������������������е�󣬿�����������
	//attitude[3] += ang_r.yaw_r * delay_t;//����Ϊ0����ʱ��Ϊ��
	float t1 = v.z_sp / g;//�÷ɻ�����ֱ�ٶȷ�����ˮƿ��ֱ�ٶȣ���������֮���ٸĽ�,�������ø����Ǻ�ƫ���ǵ�˼·
	float h = pos.z + v.z_sp * v.z_sp / (2 * g);
	float t_h = sqrt(2 * h / g);
	float s_x = v.x_sp * (t_h+t1);
	float s_y = v.y_sp * (t_h+t1);

	float d_val = sqrt((tx - s_x) * (tx - s_x) + (ty - s_y) * (ty - s_y));

	if (d_val <= r)
		return true;
	return 0;
	//	else
			//return Drop(x, y, z);��֪����ͨ���ص�������������ٽ�����Ϣ���ⲿ���ú�����

}
