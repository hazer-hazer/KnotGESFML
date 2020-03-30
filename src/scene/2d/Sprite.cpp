#include "scene/2d/Sprite.h"

Sprite::Sprite(){}

void Sprite::onready(){

}

void Sprite::onprocess(float delta){

}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	target.draw(sprite, states);
}

void Sprite::set_texture(sf::Texture * texture){
	texture->setSmooth(true);
	sprite.setTexture(*texture, true);
}
