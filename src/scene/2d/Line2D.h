#ifndef LINE_H
#define LINE_H

#include "scene/Drawable.h"
#include "core/math/Point2.h"

class Line2D : Drawable {
    public:
    
        Line2D(Point2 nfrom, Point2 nto) : Drawable(), from(nfrom), to(nto){};

        void draw(sf::RenderTarget &window);

    private:
        Point2 from;
        Point2 to;
};

#endif