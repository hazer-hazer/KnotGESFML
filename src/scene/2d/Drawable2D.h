#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "scene/2d/Node2D.h"
#include "canvas/Canvas2D.h"

#include <SFML/Graphics.hpp>

class Drawable2D : public Node2D, public sf::Drawable {

	CLASS(Drawable2D, Node2D);

	public:
		Drawable2D();
		virtual ~Drawable2D() = default;

		virtual void onready();
		virtual void onprocess(float delta);
		
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif