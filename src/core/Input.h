#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "core/math/Point2.h"
#include "core/EventHandler.h"

class Input : public EventHandler {
	public:
		Input(sf::RenderWindow &window);
		virtual ~Input(){};

		static const char * keyNames[];

		Point2 getMousePosition(bool relative = true);
		bool isKeyPressed();

		void pollEvents();

	private:
		sf::Event event;
		sf::RenderWindow &window;

		std::unordered_map <sf::Keyboard::Key, char*> keys;

		void pollKeyPressed();
		void pollKeyReleased();
		void pollMouseMove();
};

#endif