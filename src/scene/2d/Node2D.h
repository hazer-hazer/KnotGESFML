#ifndef NODE2D_H
#define NODE2D_H

#include "scene/Node.h"
#include "core/math/Vector2.h"

#include <SFML/Graphics.hpp>

class Node2D : public Node, public sf::Transformable {
	
	CLASS(Node2D, Node);

	public:
		Node2D();
        virtual ~Node2D() = default;

        virtual void onready();
        virtual void onprocess(float delta);

	// // Position
	// public:
	// 	void set_position(sf::Vector2f p);
	// 	sf::Vector2f get_position();
		
	// 	void move(sf::Vector2f p);

	// protected:
	// 	sf::Vector2f position;
};

#endif // NODE2D_H
