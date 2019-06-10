#pragma once

class Point {
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

	// TODO putting it into interface or something
	static std::vector<double> Flattened(std::vector<Point> points) {
		std::vector<double> flattened(points.size() * 2);
		for (const auto &p : points) {
			flattened.push_back(p._x);
			flattened.push_back(p._y);
		}
		return flattened;
	}

private:
	double _x;
	double _y;
};