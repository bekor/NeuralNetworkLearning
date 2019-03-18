#pragma once

struct LinearFunction
{

	LinearFunction() {
		_slope = 0;
		_shift = 0;
		_deviation = 1;
	}
	LinearFunction(long slope, long shift, long deviation) {
		_slope = slope;
		_shift = shift;
		_deviation = deviation;
	}

	virtual ~LinearFunction() {};

	void setSlope(long slope) { _slope = slope; }
	long getSlope() { return _slope; }

	void setShift(long shift) { _shift = shift; }
	long getShift() { return _shift; }

	void setWrapper(long deviation) { _deviation = deviation; }
	long getWrapper() { return _deviation; }



	long _deviation;
	long _shift;
	long _slope;
};