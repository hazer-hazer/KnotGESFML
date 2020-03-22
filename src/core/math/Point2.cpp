#include "Point2.h"

double Point2::distanceTo(Point2 p){
	return sqrt( pow(p.x - x, 2) + pow(p.y - y, 2) );
}

void Point2::move(Point2 p){
	this->x += p.x;
	this->y += p.y;
}