#include "scene/2d/Polygon.h"

void Polygon::draw(Canvas2D &canvas){
	for(unsigned int i = 0; i < points.size() - 1; i++){
    	canvas.drawPolygon(points, color);
	}
}