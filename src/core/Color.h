#ifndef COLOR_H
#define COLOR_H

#include <SFML/Graphics.hpp>

struct Color{
	struct {
		float r;
		float g;
		float b;
		float a;
	};

	sf::Color toSfColor(){
		return sf::Color(255 * r, 255 * g, 255 * b, 255 * a);
	}

	Color(){
		r = 0;
		g = 0;
		b = 0;
		a = 1.0;
	}

	Color(float r, float g, float b, float a = 1.0){
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	Color(unsigned int hex){
		this->r = ((hex >> 16) & 0xFF) / 255.0;
		this->g = ((hex >> 8) & 0xFF) / 255.0;
		this->b = ((hex) & 0xFF) / 255.0;
	}
};

#endif