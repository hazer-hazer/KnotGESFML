#include "core/Engine.h"

bool Engine::isRunning = false;

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

template <class T>
void Engine::throughTree(Node * root, std::function<void(T*)> each){
	T * casted = dynamic_cast <T*> (root);
	if(casted != nullptr){
		each(casted);
	}
	root->eachChild([this, each](Node * n){
		throughTree(n, each);
	});
}

float Engine::getFps(){
	return fps;
}

void Engine::launch(){
	if(isRunning){
		throw "Engine is already launched";
	}

	Engine::isRunning = true;

	Node * scene = scenes[currentScene];

	loopTimer.restart();

	while(canvas.isOpen()){

		// * Input
		input.pollEvents();

		// * Updating objects
		throughTree<Node>(scene, [](Node * node){
			node->update();
		});

		// * Rendering
		canvas.clear();
		
		throughTree<Drawable2D>(scene, [this](Drawable2D * node){
			node->draw(canvas);
		});

		canvas.display();

		fps = 1.f / loopTimer.restart().asSeconds();
	}
}