#include "core/Input.h"

Input::Input(){}

Input & Input::get(){
	static Input instance;
	return instance;
}

void Input::poll_events(){
	while(Canvas2D::get()->pollEvent(event)){
		switch(event.type){
			case sf::Event::Closed:
				Canvas2D::get()->close();
				break;
			case sf::Event::KeyPressed:
				poll_key_pressed();
				break;
			case sf::Event::KeyReleased:
				poll_key_released();
				break;
			case sf::Event::MouseMoved:
				poll_mouse_move();
				break;
			default:
				break;
		}
	}
}

// Keyboard
const char * Input::keyNames[] = {
	"A", "B", "C", "D",
	"E", "F", "G", "H",
	"I", "J", "K", "L",
	"M", "N", "O", "P",
	"Q", "R", "S", "T",
	"U", "V", "W", "X",
	"Y", "Z", "Num0",
	"Num1", "Num2", "Num3", "Num4",
	"Num5", "Num6", "Num7", "Num8",
	"Num9", "Escape", "LControl", "LShift",
	"LAlt", "LSystem", "RControl", "RShift",
	"RAlt", "RSystem", "Menu", "LBracket",
	"RBracket", "Semicolon", "Comma", "Period",
	"Quote", "Slash", "Backslash", "Tilde",
	"Equal", "Hyphen", "Space", "Enter",
	"Backspace", "Tab", "PageUp", "PageDown",
	"End", "Home", "Insert", "Delete",
	"Add", "Subtract", "Multiply", "Divide",
	"Left", "Right", "Up", "Down",
	"Numpad0", "Numpad1", "Numpad2", "Numpad3",
	"Numpad4", "Numpad5", "Numpad6", "Numpad7",
	"Numpad8", "Numpad9", "F1", "F2",
	"F3", "F4", "F5", "F6",
	"F7", "F8", "F9", "F10",
	"F11", "F12", "F13", "F14",
	"F15"
};

void Input::poll_key_pressed(){
	int keyEq = (int) event.key.code;
	std::string eventName = std::string("key_pressed") + keyNames[keyEq];
	if(event_exists(eventName)){
		emit(eventName);
	}
}

void Input::poll_key_released(){
	int keyEq = (int) event.key.code;
	std::string eventName = std::string("key_released") + keyNames[keyEq];
	if(event_exists(eventName)){
		emit(eventName);
	}
}

// Mouse

void Input::poll_mouse_move(){
	if(event_exists("mouse_moved")){
		emit("mouse_moved");
	}
}

sf::Vector2f Input::get_mouse_position(bool relative){
	// No non-relative now
	return Canvas2D::get()->mapPixelToCoords(sf::Mouse::getPosition(*Canvas2D::get()));
	// if(relative){
	// 	return sf::Mouse::getPosition(canvas);
	// }else{
	// 	return sf::Mouse::getPosition();
	// }
}