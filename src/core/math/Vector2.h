#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
#include <string>

#include <SFML/Graphics.hpp>

struct Vector2 {
	float x = 0;
	float y = 0;

	Vector2() : x(0.f), y(0.f) {};
	Vector2(float nx, float ny) : x(nx), y(ny) {};
	Vector2(const sf::Vector2u &v) : x((float)v.x), y((float)v.y){};
	Vector2(const sf::Vector2i &v) : x((float)v.x), y((float)v.y){};
	Vector2(const sf::Vector2f &v) : x(v.x), y(v.y){};

	Vector2 operator * (const float & num){
		return Vector2(x * num, y * num);
	}

	Vector2 & operator *= (const float & num){
		x *= num;
		y *= num;
		return *this;
	}

	Vector2 & operator *= (const Vector2 & v){
		x *= v.x;
		y *= v.y;
		return *this;
	}

	float distance_to(Vector2 p);
	void move(Vector2 p);

	std::string to_string();

	sf::Vector2f to_sf() const {
		return sf::Vector2f(x, y);
	}
};

#endif