#pragma once

class Point{
public:
	Point() {
		_x = 0;
		_y = 0;
	}
	Point(double x, double y) {
		_x = x;
		_y = y;
	}

	virtual ~Point() {};

	double getX() { return _x; }
	void setX(double x) { _x = x; }

	double getY() { return _y; }
	void setY(double y) { _y = y; }
	
private:
	double _x;
	double _y;
};