#define SFML_STATIC

#include <iostream>

#include "core/Engine.h"

#include "scene/2d/Label.h"
#include "scene/2d/Particles2D.h"

#include "project/ProjectSettings.h"
#include "project/FileHandler.h"

using std::cout;
using std::endl;

int main(){

	try{

		FileHandler file("file.lua");

		cout << file.get<int>("number") << endl;

		// Engine engine;

		// Node * root = new Node;

		// Particles2D * particles = new Particles2D;

		// root->add_child(particles);

		// // FPS Meter
		// Label * fpsMeter = new Label;
		// fpsMeter->setPosition(0, 0);
		// fpsMeter->set_color(Color::CYAN);
		// fpsMeter->set_font(ResourceHolder::fonts.load("roboto"));

		// fpsMeter->set_process([&engine, &fpsMeter](float delta){
		// 	fpsMeter->set_text(std::to_string((int)engine.get_fps()));
		// });

		// root->add_child(fpsMeter);

		// Scene scene;
		// scene.set_root(root);

		// engine.add_scene(scene);

		// engine.launch();

	}catch(const char * message){
		std::cerr << message << std::endl;
	}catch(std::string message){
		std::cerr << message << std::endl;
	}

	return 0;
}