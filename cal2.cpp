// 3dcal2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "cal2.h"

cal2::cal2(int _a, int _b, double _h)
{
    a = _a;
    b = _b;
    h = _h;
}

std::vector<double> cal2::cal_solve()
{
    std::vector<double> coord;
    double x, y;
    x = b * h / (f * sin(angle) + f * cos(angle));
    y = h / (tan(angle + atan(a / f)));
    coord.push_back(x);
    coord.push_back(y);
    coord.push_back(h);
    return coord;
}

int main()
{
    std::vector<double> m;
    cal2 a(1, 1, 1);
    m = a.cal_solve();
    std::cout << m[0] << "   " << m[1] << "    " << m[2];

}

