#ifndef LINE_H
#define LINE_H

#include "scene/2d/Drawable2D.h"
#include "core/math/Point2.h"
#include "canvas/Canvas2D.h"

#include <vector>

class Polygon : public Drawable2D {
    public:
    	
    	Polygon(std::vector <Point2> ps, Color clr = Color::BLACK) : color(clr), points(ps){};

        virtual ~Polygon() = default;

        void draw(Canvas2D &canvas);

    private:
    	// Move to inherited
    	Color color;

    	std::vector <Point2> points;
};

#endif