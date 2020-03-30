#ifndef SPRITE_H
#define SPRITE_H

#include "scene/2d/Drawable2D.h"
#include "core/ResourceHolder.h"

class Sprite : public Drawable2D {

	CLASS(Sprite, Drawable2D);

	public:
		// Constructor with path to texture file
		Sprite();
        virtual ~Sprite() = default;

        virtual void onready();
        virtual void onprocess(float delta);
        
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		void set_texture(sf::Texture * texture);

		const Vector2 get_size(){
			return Vector2(sprite.getTexture()->getSize());
		};

	private:
		sf::Sprite sprite;
};

#endif