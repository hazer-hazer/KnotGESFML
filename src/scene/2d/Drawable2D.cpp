#include "scene/2d/Drawable2D.h"

void Drawable2D::drawChildren(sf::RenderTarget &window){
    for(auto child : getChildrenArray()){
        Drawable * drawable = dynamic_cast <Drawable *> (child);
        if(drawable == nullptr){
            continue;
        }
        drawable->draw(window);
    }
}