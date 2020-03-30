#include "scene/2d/Particles2D.h"

Particles2D::Particles2D(){}

void Particles2D::onready(){
	particles.clear();
	particles.resize(amount);
	sf::Texture noneTexture;
	noneTexture.create(5, 5);
	for(std::size_t i = 0; i < amount; i++){
		particles[i].sprite.setTexture(noneTexture);
		reset_particle(i);
	}
}

void Particles2D::onprocess(float delta){
	for(std::size_t i = 0; i < amount; i++){
		Particle &p = particles[i];

		p.lifetime -= delta;

		if(p.lifetime <= 0.f){
			reset_particle(i);
			continue;
		}

		// Apply gravity
		p.velocity += sf::Vector2f(0, gravity * delta);

		// Apply fadeout
		if(fadeout){
			sf::Color color = p.sprite.getColor();
			color.a = p.lifetime / lifetime * 255;
			p.sprite.setColor(color);
		}
		p.move(p.velocity * delta * speed);
	}
}

void Particles2D::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	for(const Particle &p : particles){
		target.draw(p);
	}
}


void Particles2D::reset_particle(std::size_t index){
	particles[index].lifetime = std::fmod(((float)std::rand()), lifetime);
	particles[index].setPosition(getPosition());
	particles[index].sprite.setColor(color.to_sf_color());

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

	particles[index].velocity = vel;
}

// Amount
void Particles2D::set_amount(std::size_t amount){
	this->amount = amount;
}

std::size_t Particles2D::get_amount(){
	return amount;
}

// Lifetime
void Particles2D::set_lifetime(float lifetime){
	this->lifetime = lifetime;
}

float Particles2D::get_lifetime(){
	return lifetime;
}

// Gravity
void Particles2D::set_gravity(float gravity){
	this->gravity = gravity;
}

float Particles2D::get_gravity(){
	return gravity;
}

// Speed
void Particles2D::set_speed(float speed){
	this->speed = speed;
}

float Particles2D::get_speed(){
	return speed;
}

// Shape
void Particles2D::set_shape(Shape shape){
	this->shape = shape;
}

Particles2D::Shape Particles2D::get_shape(){
	return shape;
}

// Color
void Particles2D::set_color(Color color){
	this->color = color;
}

Color Particles2D::get_color(){
	return color;
}

// Fadeout
void Particles2D::set_fadeout(bool fadeout){
	this->fadeout = fadeout;
}

bool Particles2D::get_fadeout(){
	return fadeout;
}