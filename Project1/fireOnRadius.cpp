#include "def.h"
bool myplane::Drop2(float x, float y, float z)
{
	const float g = 9.8;
	const float r = 3;//�ۺ�Ч�ʺ�׼ȷ�ʵ���
	const float delay_t = 0.5;
	const float pi = 3.1415926;
	//x,y,z���Ի���Ϊԭ���ENUϵ
	float tx = x - v.x_sp * delay_t;
	float ty = y - v.y_sp * delay_t;
	float tz = z - v.z_sp * delay_t;//����任���õ��б���Էɻ���λʸ��ENU����ϵ�¡�
	pos.z += v.z_sp * delay_t;
	 //�������3mԲ���ж�Ϊ���ǰ���£���һ����Χ�ڶ��᷵���棬ѡ��ѵ�Ͷ��ʱ��������С�жϵ�r��Χ�ȽϿ��ĸ�׼ȷ�ʸߣ�����ǿ�ж�����Ƿ��ڴ�ֱ�ڷɻ������ֱ�����Ա�֤������㹻��Ļ�ռ䲻��ƫ��Բ��̫��

	//attitude[2] +=ang_r.pitch_r*delay_t;//̧ͷ�Ǹ���pitch�ļ��ٶȱȽ�С������������������е�󣬿�����������
	//attitude[3] += ang_r.yaw_r * delay_t;//����Ϊ0����ʱ��Ϊ��
	float t1 = v.z_sp / g;//�÷ɻ�����ֱ�ٶȷ�����ˮƿ��ֱ�ٶȣ���������֮���ٸĽ�,�������ø����Ǻ�ƫ���ǵ�˼·
	//float h = pos.z + v.z_sp * v.z_sp / (2 * g);/�����Ϸ��ٶȵ�ʱ��
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
	//����ʱ��֣���Ϊ�����Ҷ�ûͶ����ʱ��һ����Ҳ�ǿ��Էֳ����µģ����ʱ�䵽��һ��ʱ���ֱ�Ӷ�����������������
}