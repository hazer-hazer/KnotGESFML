#ifndef POINT2_H
#define POINT2_H

#include <cmath>
#include <string>

struct Point2 {
	double x = 0;
	double y = 0;

	Point2() : x(0), y(0) {};
	Point2(double nx, double ny) : x(nx), y(ny) {};

	double distanceTo(Point2 p);
	void move(Point2 p);

	std::string toString(){
		return std::to_string(x) + ":" + std::to_string(y);
	};
};

#endif // POINT2_H
