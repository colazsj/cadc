#ifndef _CAL2_H_
#define _CAL2_H_

#include <iostream>
#include <cmath>
#include <vector>


const double dx = 1;
const double dy = 1;
//dx,dyΪ���ص����ʵ����ߴ�

const double f = 1;//����

const double angle = 0.5;

class cal2
{
private:
	int a, b;//a,bΪ��������
	double h;//�ɿػ�÷ɻ��߶�
	double angle;

public:
	cal2(int _a, int _b, double _h);
	std::vector<double>  cal_solve();

};

#endif // !_CAL2_H_

#pragma once
