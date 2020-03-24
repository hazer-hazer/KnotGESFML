#include "scene/2d/Sprite.h"

Sprite::Sprite(std::string name){
	sf::Texture * texture = new sf::Texture(ResourceHolder::textures.load(name));
	setTexture(texture);
}

Sprite::Sprite(sf::Texture * texture){
	setTexture(texture);
}

void Sprite::setTexture(sf::Texture * texture){
	texture->setSmooth(true);
	sprite.setTexture(*texture, true);
}

void Sprite::draw(Canvas2D &canvas){
	sprite.setPosition(position.x, position.y);
	canvas.drawSprite(sprite);
}