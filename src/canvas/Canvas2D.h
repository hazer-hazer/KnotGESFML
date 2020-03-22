#ifndef SFCANVAS2D_H
#define SFCANVAS2D_H

#define DEFAULT_FPS 60

#include "core/math/Point2.h"
#include <SFML/Graphics.hpp>

class Canvas2D {
    public:
        Canvas2D(sf::VideoMode size, sf::String title);
        ~Canvas2D(){};

        const sf::RenderWindow & getWindow() const;

        void clear(sf::Color color);
        void display();
        bool isOpen();

        void handleEvents();

        void drawLine(Point2 from, Point2 to);

    protected:
        sf::RenderWindow window;
};

#endif