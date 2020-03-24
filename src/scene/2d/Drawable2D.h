#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "scene/2d/Node2D.h"
#include "canvas/Canvas2D.h"

#include <SFML/Graphics.hpp>

class Drawable2D : public Node2D {
    public:
        Drawable2D(){};

        virtual ~Drawable2D() = default;

        // void drawTree(Canvas2D &canvas);
        
        virtual void draw(Canvas2D &canvas) = 0;
};

#endif