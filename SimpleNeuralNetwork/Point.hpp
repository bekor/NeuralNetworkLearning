#pragma once
#include "LinearFunction.hpp"

class Point {
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(double Xin, double Yin) {
		x = Xin;
		y = Yin;
	}

	virtual ~Point() {};

	static Point CalculatePointFromLinearFunction(LinearFunction lnf, double rndX) {
		double y = lnf.getSlope() * rndX + lnf.getShift();
		return Point(rndX + lnf.getWrapper(), y);
	}

	double x;
	double y;
};