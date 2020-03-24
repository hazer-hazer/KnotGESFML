#include "core/Engine.h"

Engine::Engine() : canvas({ 1080, 720 }, "TITLE"), input(canvas.getWindow()) {
}

void Engine::addScene(Node * node){
	scenes.push_back(node);
	currentScene = scenes.size() - 1;
}

Node * Engine::getCurrentScene(){
	return getScene(currentScene);
}

Node * Engine::getScene(unsigned int position){
	if(position >= scenes.size()){
		throw "Scene ID out of range";
	}
	return scenes.at(position);
}

Input & Engine::getInput(){
	return input;
}

void Engine::renderScene(Node * root){
	print(typeid(*root).name());
	Drawable2D * drawable = dynamic_cast <Drawable2D *> (root);
	if(drawable != nullptr){
		drawable->draw(canvas);
	}
	root->eachChild([this](Node * n){
		renderScene(n);
	});
}

void Engine::launch(){
	while(canvas.isOpen()){

		input.pollEvents();

		Node * scene = scenes[currentScene];

		canvas.clear();

		renderScene(scene);

		canvas.display();
	}
}