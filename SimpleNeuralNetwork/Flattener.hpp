#pragma once

#include <memory>
#include <vector>

#include "Point.hpp"

struct Flattener
{
public:
	static std::vector<double> FlattenPoints(std::vector<std::shared_ptr<Point>> points) {
		std::vector<double> flattened(points.size() * 2);
		for(const auto &p : points) {
			flattened.push_back(p->getX());
			flattened.push_back(p->getY());
		}
		return flattened;
	}

};