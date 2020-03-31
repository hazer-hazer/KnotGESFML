#include "scene/2d/Particles2D.h"

Particles2D::Particles2D(){}

void Particles2D::onready(){
	particles.clear();
	particles.resize(amount);
	for(Particle &p : particles){
		p.shape.setSize(sf::Vector2f(size, size));
		p.shape.setTexture(&texture);
		reset_particle(p);
	}
}

void Particles2D::onprocess(float delta){
	for(Particle &p : particles){
		p.lifetime -= delta;

		if(p.lifetime <= 0.f){
			reset_particle(p);
			continue;
		}

		// Apply gravity
		p.velocity += sf::Vector2f(0, gravity * delta);

		// Apply fadeout
		if(fadeout){
			sf::Color color = p.shape.getFillColor();
			color.a = p.lifetime / lifetime * 255;
			p.shape.setFillColor(color);
		}
		p.move(p.velocity * delta * speed);
	}
}

void Particles2D::reset_particle(Particle &p){
	p.lifetime = std::fmod(((float)std::rand()), lifetime);
	p.setPosition(getPosition());
	p.shape.setFillColor(color.to_sf_color());

	sf::Vector2f vel;
	switch(shape){
		case SQUARE:{
			float width = (std::rand() % 10) - 5.0f;
			float height = (std::rand() % 10) - 5.0f;
			vel = sf::Vector2f(width, height);
		}
		break;
		case CIRCLE:{
			float angle = (std::rand() % 360) * 3.14f / 180.f;
			vel = sf::Vector2f(std::cos(angle), std::sin(angle));
		}
		break;
		case POINT:
		default:{
			float angle = (std::rand() % 360) * 3.14f / 180.f;
			float s = (std::rand() % 5) + 5.f;
			vel = sf::Vector2f(std::cos(angle) * s, std::sin(angle) * s);
		}
	}

	p.velocity = vel;
}

void Particles2D::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	for(const Particle &p : particles){
		target.draw(p);
	}
}

// Texture
void Particles2D::set_texture(sf::Texture & texture){
	texture.setSmooth(true);
	this->texture = texture;
}

sf::Texture & Particles2D::get_texture(){
	return texture;
}

// Shape
void Particles2D::set_shape(Shape shape){
	this->shape = shape;
}

Particles2D::Shape Particles2D::get_shape(){
	return shape;
}