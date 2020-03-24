#ifndef SPRITE_H
#define SPRITE_H

#include "scene/2d/Drawable2D.h"
#include "core/ResourceHolder.h"

class Sprite : public Drawable2D {
	public:
		Sprite(std::string name);
		Sprite(sf::Texture * texture);

        virtual ~Sprite() = default;

		void draw(Canvas2D &canvas);
		void setTexture(sf::Texture * texture);

	private:
		sf::Sprite sprite;
};

#endif