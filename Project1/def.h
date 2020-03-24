#include <iostream>
#include <vector>
using namespace std;

struct position {
	double x, y, z;
	// ��λ��GPS����һ�¡�
};

struct attitude
{
	vector <double> att;
};

struct tri_sp {
	double x_sp, y_sp, z_sp; //m/s
};

struct ang_rate
{
	double roll_r, pitch_r, yaw_r;
};
struct plane {
	position pos;
	attitude att;
	tri_sp t_sp;
	ang_rate ang_r;
	double air_speed; //��λm/s
	double speed; //��λm/s
};
