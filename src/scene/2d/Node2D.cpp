#include "scene/2d/Node2D.h"
#include <iostream>

Node2D::Node2D() : Node() {
    std::cout << "NODE2D" << std::endl;
}

void Node2D::setPosition(Point2 p){
    this->position = p;
}

void Node2D::setPosition(sf::Vector2f p){
    this->position = Point2(p.x, p.y);
}

Point2 Node2D::getPosition(){
    return position;
}

void Node2D::move(Point2 p){
    position.move(p);
}