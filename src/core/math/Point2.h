#ifndef POINT2_H
#define POINT2_H

#include <cmath>

struct Point2 {
	double x = 0;
	double y = 0;

	Point2() : x(0), y(0) {};
	Point2(double nx, double ny) : x(nx), y(ny) {};

	double distanceTo(Point2 p);
	void move(Point2 p);
};

#endif // POINT2_H
