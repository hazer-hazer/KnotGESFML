#ifndef SFCANVAS2D_H
#define SFCANVAS2D_H

#define DEFAULT_FPS 60

#include "core/Color.h"
#include "core/math/Vector2.h"
#include "core/Object.h"
#include <SFML/Graphics.hpp>

class Canvas2D : public sf::RenderWindow, public Object {

	CLASS(Canvas2D, Object);

	private:
		Canvas2D(sf::VideoMode size,
				 const sf::String &title,
				 uint32_t style = sf::Style::Default,
				 const sf::ContextSettings &settings = sf::ContextSettings());

		static Canvas2D * instance;

	// Delete
	public:
	    Canvas2D(const Canvas2D &) = delete;
	    Canvas2D(Canvas2D &&) = delete;
	    Canvas2D & operator = (const Canvas2D &) = delete;
	    Canvas2D & operator = (Canvas2D &&) = delete;

	// Singleton
	public:
		static Canvas2D * create(sf::VideoMode size,
						  const sf::String &title,
						  uint32_t style = sf::Style::Default,
						  const sf::ContextSettings &settings = sf::ContextSettings());
		static Canvas2D * get();

		int test;

		int check(){
			return test;
		}

	// Clear
	private:
		Color clear_color;

	public:
		void clear();
		void set_clear_color(const Color &color = Color::BLACK);
};

#endif