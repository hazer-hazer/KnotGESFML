#include "Label.h"

Label::Label(){}

void Label::onready(){

}

void Label::onprocess(float delta){

}

void Label::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();

	target.draw(label, states);
}

void Label::set_text(std::string text){
	label.setString(text);
}

void Label::set_font(sf::Font &font){
	label.setFont(font);
}

void Label::set_font_size(unsigned int size){
	label.setCharacterSize(size);
}

void Label::set_style(uint32_t s){
	label.setStyle(s);
}

void Label::set_color(const Color &c){
	label.setFillColor(c.to_sf_color());
}