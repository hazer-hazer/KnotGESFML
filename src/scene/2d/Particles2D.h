#ifndef PARTICLES2D_H
#define PARTICLES2D_H

// #define PARTICLES2D_DEFAULT_AMOUNT 10
// #define PARTICLES2D_DEFAULT_LIFETIME 5.0f
// #define PARTICLES2D_DEFAULT_GRAVITY 10.0f
// #define PARTICLES2D_DEFAULT_SPEED 50.0f
// #define PARTICLES2D_DEFAULT_EMITTING true

#include "scene/2d/Drawable2D.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "core/ResourceHolder.h"

class Particles2D : public Drawable2D {

	CLASS(Particles2D, Drawable2D);

	public:
		Particles2D();
		virtual ~Particles2D() = default;

		virtual void onready();
		virtual void onprocess(float delta);

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	// Amount
	public:
		void set_amount(std::size_t amount);
		std::size_t get_amount();

	private:
		std::size_t amount = 10;

	// Lifetime
	public:
		void set_lifetime(float lifetime);
		float get_lifetime();

	private:
		float lifetime = 5.0f;

	// Gravity
	public:
		void set_gravity(float gravity);
		float get_gravity();

	private:
		float gravity = 10.0f;

	// Speed
	public:
		void set_speed(float speed);
		float get_speed();

	private:
		float speed = 50.0f;

	// Shape
	public:
		enum Shape{
			SQUARE,
			CIRCLE,
			POINT
		};
		void set_shape(Shape shape);
		Particles2D::Shape get_shape();

	private:
		Shape shape = POINT;

	// Color
	public:
		void set_color(Color color);
		Color get_color();

	private:
		Color color = Color::WHITE;

	// Fadeout
	public:
		void set_fadeout(bool fadeout);
		bool get_fadeout();

	private:
		bool fadeout = true;

	// Texture
	public:
		void set_texture(sf::Texture & texture);
		sf::Texture & get_texture();

	private:
		sf::Texture texture;

	// Size
	public:
		void set_size(int size);
		int get_size();

	private:
		int size;

	// Particles
	private:
		struct Particle : public sf::Drawable, public sf::Transformable {
			float lifetime;
			sf::Vector2f velocity;
			sf::RectangleShape shape;

			void draw(sf::RenderTarget &target, sf::RenderStates states) const {
				states.transform *= getTransform();
				target.draw(shape, states);
			}
		};

		std::vector <Particle> particles;

		void reset_particle(Particle &p);
};

#endif