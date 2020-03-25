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

using std::cout;
using std::endl;

int main(){
	try{
		Engine engine;

		Sprite * sprite = new Sprite(ResourceHolder::textures.load("image"));

		Node * scene = new Node();

		Label * label = new Label("FPS", ResourceHolder::fonts.load("roboto"), 32);
		label->setColor(Color::CYAN);

		label->_process([&label, &engine](float delta){
			label->setString((int)engine.getFps());
		});

		scene->addChild(sprite);
		scene->addChild(label);

		engine.addScene(scene);

		Input & input = engine.getInput();

		input.on("mouseMoved", [&sprite, &input](){
			sprite->setPosition(input.getMousePosition());
		});

		sprite->_process([&sprite](float delta){
			sprite->move(Point2(delta * 100, delta * 100));
		});

		engine.launch();

	}catch(const char * message){
		std::cerr << message << std::endl;
	}
}