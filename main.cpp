#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "scene/2d/Line2D.h"

int main(){

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    window.clear(sf::Color::White);

    Line2D * line = new Line2D(Point2(0, 0), Point2(100, 100));

    line->draw(window);

    window.display();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}