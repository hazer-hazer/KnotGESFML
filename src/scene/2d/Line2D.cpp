#include "scene/2d/Line2D.h"

void Line2D::draw(Canvas2D &canvas){
    canvas.drawLine(from, to);
}