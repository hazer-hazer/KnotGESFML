#include "canvas/Canvas2D.h"

Canvas2D::Canvas2D(sf::VideoMode size, sf::String title) : window(size, title) {
	window.setPosition({ window.getPosition().x, 0 });
	window.setFramerateLimit(DEFAULT_FPS);
}

void Canvas2D::clear(sf::Color color){
	window.clear(color);
}

void Canvas2D::display(){
	window.display();
}

bool Canvas2D::isOpen(){
	return window.isOpen();
}

void Canvas2D::handleEvents(){
	sf::Event event;
	while (window.pollEvent(event)){
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

const sf::RenderWindow & Canvas2D::getWindow() const {
	return window;
}

void Canvas2D::drawLine(Point2 from, Point2 to){
	sf::Vertex line[2];
	line[0].position = sf::Vector2f(from.x, from.y);
	line[0].color = sf::Color::Black;
	line[1].position = sf::Vector2f(to.x, to.y);
	line[1].color = sf::Color::Black;

	window.draw(line, 1, sf::Quads);
}