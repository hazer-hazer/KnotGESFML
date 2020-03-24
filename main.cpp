#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "canvas/Canvas2D.h"
#include "core/Color.h"
#include "core/Input.h"
#include "core/ResourceHolder.h"

#include "scene/2d/Polygon.h"
#include "scene/2d/Sprite.h"
#include "scene/2d/Label.h"
#include "core/Engine.h"

int main(){
	try{
		Engine engine;

		Sprite * sprite = new Sprite("image");

		Node * scene = new Node();

		Label * label = new Label("FPS", ResourceHolder::fonts.load("roboto"), 32);
		label->setColor(Color::WHITE);

		scene->addChild(sprite);
		scene->addChild(label);

		engine.addScene(scene);

		Input & input = engine.getInput();

		input.on("mouseMoved", [&sprite, &input](){
			sprite->setPosition(input.getMousePosition());
		});

		engine.launch();

	}catch(const char * message){
		std::cerr << message << std::endl;
	}
}