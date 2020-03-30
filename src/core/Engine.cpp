#include "core/Engine.h"

Engine::Engine() : input(Input::get()){
	Canvas2D::create(sf::VideoMode(1080, 720), "TITLE");
	// Canvas2D::get()->setView(sf::View(sf::FloatRect(0, 0, 1080, 720)));
}

// Scenes
void Engine::add_scene(Scene &scene){
	scenes.push_back(scene);
	set_current_scene(scenes.size() - 1);
	
	scene.through_tree<Node>([](Node * node){
		node->onready();
	});
}

Scene & Engine::get_scene(std::size_t position){
	if(position >= scenes.size()){
		throw "Scene ID out of range";
	}

	return scenes.at(position);
}

Scene & Engine::get_current_scene(){
	return get_scene(current_scene);
}

void Engine::set_current_scene(std::size_t position){
	current_scene = position;
}

// Input
Input & Engine::get_input(){
	return input;
}

// Engine

float Engine::get_fps(){
	return fps;
}

void Engine::launch(){

	Scene &scene = get_current_scene();

	loop_timer.restart();

	while(Canvas2D::get()->isOpen()){

		// * Input
		input.poll_events();

		// * Updating objects
		scene.through_tree<Node>([this](Node * node){
			node->process();
		});

		// * Rendering
		Canvas2D::get()->clear();
		
		print(std::to_string(get_fps()) + " fps");		

		scene.through_tree<Drawable2D>([this](Drawable2D * node){
			Canvas2D::get()->draw(*node);
		});

		Canvas2D::get()->display();

		fps = 1.f / loop_timer.restart().asSeconds();
	}
}
