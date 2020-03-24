#ifndef SFCANVAS2D_H
#define SFCANVAS2D_H

#define DEFAULT_FPS 60

#include "core/math/Point2.h"
#include "core/Color.h"
#include <SFML/Graphics.hpp>

#include <iostream>

using std::cout;
using std::endl;

class Canvas2D {
    public:
        Canvas2D(sf::VideoMode size, sf::String title, uint32_t style = sf::Style::Default);
        ~Canvas2D(){};

        sf::RenderWindow & getWindow();

        void clear();
        void display();
        bool isOpen();

        void setClearColor(Color clearColor);

        void draw(const sf::Drawable & drawable);
        void drawPolygon(std::vector <Point2> points, Color color = Color::BLACK);
        void drawSprite(sf::Sprite &sprite);

    protected:
        sf::RenderWindow window;
        
        Color clearColor;
};

#endif