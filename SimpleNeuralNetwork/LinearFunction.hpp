#pragma once
#include "Point.hpp"

class LinearFunction
{
public:
	LinearFunction() {
		_slope = 0;
		_shift = 0;
	}
	LinearFunction(long slope, long shift) {
		_slope = slope;
		_shift = shift;
	}

	virtual ~LinearFunction() {};

	void setSlope(long slope) { _slope = slope; }
	long getSlope() { return _slope; }

	void setShift(long shift) { _shift = shift; }
	long getShift() { return _shift; }


	Point CalculatePointAroundLinearFunction (double rndX, int deviation) {
		double y = this->_slope * rndX + this->_shift;
		return Point(rndX, y + deviation);
	}


private:
	long _shift;
	long _slope;
};