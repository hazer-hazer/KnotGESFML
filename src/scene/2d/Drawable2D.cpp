#include "scene/2d/Drawable2D.h"

void Drawable2D::drawChildren(Canvas2D &canvas){
    for(auto child : getChildren()){
        Drawable2D * drawable = dynamic_cast <Drawable2D *> (child);
        if(drawable == nullptr){
            continue;
        }
        drawable->draw(canvas);
    }
}