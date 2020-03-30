#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "core/math/Vector2.h"
#include "canvas/Canvas2D.h"

/*
 * SINGLETON INPUT
*/

class Input : public Object {
	
	CLASS(Input, Object);

	private:
		Input();

	// Delete
	public:
		Input(const Input &) = delete;
		Input(Input &&) = delete;
		Input & operator = (const Input &) = delete;
		Input & operator = (Input &&) = delete;

	// Singleton
	public:
		// Create is not in need now, but maybe usefull in the future
		// static Input & create();
		static Input & get();

	// Events
	public:
		void poll_events();

	private:
		sf::Event event;

	// Keyboard
	public:
		void poll_key_pressed();
		void poll_key_released();
		
	private:
		static const char * keyNames[];
		std::unordered_map <sf::Keyboard::Key, char*> keys;

	// Mouse
	public:
		void poll_mouse_move();
		sf::Vector2f get_mouse_position(bool relative = true);

};

#endif