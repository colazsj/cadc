#ifndef _CAL2_H_
#define _CAL2_H_

#include <iostream>
#include <cmath>
#include <vector>


const double dx = 1;
const double dy = 1;
//dx,dy为像素点的真实物理尺寸

const double f = 1;//焦距

const double angle = 0.5;

class cal2
{
private:
	int a, b;//a,b为像素坐标
	double h;//飞控获得飞机高度
	double angle;

public:
	cal2(int _a, int _b, double _h);
	std::vector<double>  cal_solve();

};

#endif // !_CAL2_H_

#pragma once
