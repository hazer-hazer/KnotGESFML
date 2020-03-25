#ifndef ENGINE_H
#define ENGINE_H

#include "core/Object.h"
#include "scene/Node.h"
#include "core/Input.h"
#include "canvas/Canvas2D.h"
#include "scene/2d/Drawable2D.h"

#include <functional>

class Engine : public Object {
	public:
		Engine();
		virtual ~Engine() = default;

		void addScene(Node * scene);
		Node * getCurrentScene();
		Node * getScene(unsigned int position);

		std::function <void(Input & input, Node * scene)> gameLogic;

		// Go through tree starting at given root
		// and calling given function with casted Node.
		// This is a universal way to do each cycle step
		template <typename T>
		void throughTree(Node * root, std::function<void(T*)> each);

		Input & getInput();

		void launch();

		float getFps();

	private:
		static bool isRunning;

		sf::Clock loopTimer;
		float fps;

		unsigned int currentScene = 0;
		std::vector <Node *> scenes;

		Canvas2D canvas;
		Input input;

};

#endif