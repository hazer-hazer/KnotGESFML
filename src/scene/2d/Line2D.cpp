#include "scene/2d/Line2D.h"

#include <SFML/Graphics.hpp>

void Line2D::draw(sf::RenderTarget &window){
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(from.x, from.y);
    line[0].color = sf::Color::Black;
    line[1].position = sf::Vector2f(to.x, to.y);
    line[1].color = sf::Color::Black;

    window.draw(line, 1, sf::Quads);
}