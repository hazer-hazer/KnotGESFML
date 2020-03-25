#ifndef SPRITE_H
#define SPRITE_H

#include "scene/2d/Drawable2D.h"
#include "core/ResourceHolder.h"

class Sprite : public Drawable2D {
	public:
		// Constructor with path to texture file
		Sprite(std::string path);

		// Constructor with existent texture as parameter
		Sprite(sf::Texture * texture);

		// Constructor with texture loaded with ResourceHolder
		Sprite(sf::Texture & texture);

        virtual ~Sprite() = default;

		void draw(Canvas2D &canvas);
		void setTexture(sf::Texture * texture);

	private:
		sf::Sprite sprite;
};

#endif