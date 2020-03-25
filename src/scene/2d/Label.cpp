#include "Label.h"

void Label::setString(std::string str){
	text.setString(str);
}

void Label::setString(int num){
	text.setString(std::to_string(num));
}

void Label::setString(float num){
	text.setString(std::to_string(num));
}

void Label::setFont(sf::Font &font){
	text.setFont(font);
}

void Label::setFontSize(unsigned int size){
	text.setCharacterSize(size);
}

void Label::setStyle(uint32_t s){
	text.setStyle(s);
}

void Label::setColor(Color c){
	text.setFillColor(c.toSfColor());
}

void Label::draw(Canvas2D &canvas){
	text.setPosition(position.x, position.y);
	canvas.draw(text);
}