#include "canvas/Canvas2D.h"

Canvas2D::Canvas2D(sf::VideoMode size, sf::String title, uint32_t style) : window(size, title, style) {
	window.setPosition({ window.getPosition().x, window.getPosition().y });
	window.setFramerateLimit(DEFAULT_FPS);

	window.setActive();

	setClearColor(Color::BLACK);
}

void Canvas2D::clear(){
	window.clear(clearColor.toSfColor());
}

void Canvas2D::setClearColor(Color clearColor){
	this->clearColor = clearColor;
}

void Canvas2D::display(){
	window.display();
}

bool Canvas2D::isOpen(){
	return window.isOpen();
}

sf::RenderWindow & Canvas2D::getWindow() {
	return window;
}

void Canvas2D::draw(const sf::Drawable & drawable){
	window.draw(drawable);
}

void Canvas2D::drawPolygon(std::vector <Point2> points, Color color){
	int count = points.size();
	sf::Vertex poly[count];
	for(int i = 0; i < count; i++){
		poly[i].position = sf::Vector2f(points[i].x, points[i].y);
		poly[i].color = color.toSfColor();
	}

	window.draw(poly, count, sf::Quads);
}