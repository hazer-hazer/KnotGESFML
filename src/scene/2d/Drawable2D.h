#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "scene/2d/Node2D.h"

class Drawable2D : public Node2D {
    public:
        Drawable2D(){};
        ~Drawable2D(){};

        void drawChildren(sf::RenderTarget &window);
        
        void draw(sf::RenderTarget &window){};
};

#endif