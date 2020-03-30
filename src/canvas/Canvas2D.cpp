#include "canvas/Canvas2D.h"

#include <ctime>

Canvas2D * Canvas2D::instance = nullptr;

Canvas2D::Canvas2D(sf::VideoMode size,
				   const sf::String &title,
				   uint32_t style,
				   const sf::ContextSettings &settings)
: sf::RenderWindow(size, title, style, settings){
	
	setFramerateLimit(DEFAULT_FPS);
	
	setVerticalSyncEnabled(true);

	setActive();

	set_clear_color(Color::BLACK);

	emit("created");
}

Canvas2D * Canvas2D::create(sf::VideoMode size,
							const sf::String &title,
							uint32_t style,
							const sf::ContextSettings &settings)
{
	if(instance){
		throw "Instance redefinition";
	}
	return instance = new Canvas2D(size, title, style, settings);
}

Canvas2D * Canvas2D::get(){
	if(!instance){
		throw "Instance is not created";
	}
	return instance;
}

void Canvas2D::clear(){
	sf::RenderWindow::clear(clear_color.to_sf_color());
}

void Canvas2D::set_clear_color(const Color &color){
	this->clear_color = color;
}