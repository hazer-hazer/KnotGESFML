#ifndef ENGINE_H
#define ENGINE_H

#include "core/Object.h"
#include "scene/Node.h"
#include "core/Input.h"
#include "canvas/Canvas2D.h"
#include "scene/2d/Drawable2D.h"

class Engine : public Object {
	public:
		Engine();
		virtual ~Engine() = default;

		void addScene(Node * scene);
		Node * getCurrentScene();
		Node * getScene(unsigned int position);

		void renderScene(Node * root);

		Input & getInput();

		void launch();

	private:
		unsigned int currentScene = 0;
		std::vector <Node *> scenes;

		Canvas2D canvas;
		Input input;

};

#endif