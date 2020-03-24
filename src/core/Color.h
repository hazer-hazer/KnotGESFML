#ifndef COLOR_H
#define COLOR_H

#include <SFML/Graphics.hpp>
#include <string>

struct Color{
	struct {
		float r;
		float g;
		float b;
		float a;
	};

	static Color BLACK;
	static Color WHITE;
	static Color GRAY;
	static Color RED;
	static Color GREEN;
	static Color BLUE;
	static Color YELLOW;
	static Color CYAN;
	static Color ORANGE;
	static Color MAGENTA;

	sf::Color toSfColor(){
		return sf::Color(255 * r, 255 * g, 255 * b, 255 * a);
	}

	std::string toString(){
		return std::to_string(r) + " " + std::to_string(g) + " " + std::to_string(b);
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

	Color(std::string color){
		// Implement color constructor for string
		// HEX #ffffff
		// Color name black, white and etc. from this static
	}

	Color operator + (Color c){
		return Color(r + c.r / 2, g + c.g / 2, b + c.b);
	}
};

#endif