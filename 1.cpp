
#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<int> a(2);
    int i;
    for (i = 0; i < 2; i++)
        cout << a[i];
}

//input:飞机的姿态以及坐标（减小gps定位误差），速度，三轴速度，图像
//相机标定：得到畸变矩阵以及相机内参矩阵。solvepnp(外参)，即可将二维坐标转换为三维坐标
//图像——>得到三维坐标（还需相机与飞控之间的位置变换矩阵
//飞控数据，三维坐标——>判断是否投弹——>（否）反馈给飞控，调整姿态
