#ifndef LINE_H
#define LINE_H

#include "scene/2d/Drawable2D.h"
#include "core/math/Point2.h"
#include "canvas/Canvas2D.h"

class Line2D : public Drawable2D {
    public:
    
        Line2D(Point2 nfrom, Point2 nto) : Drawable2D(), from(nfrom), to(nto){};

        void draw(Canvas2D &canvas);

    private:
        Point2 from;
        Point2 to;
};

#endif