#ifndef ENGINE_H
#define ENGINE_H

#include "core/Object.h"
#include "scene/Node.h"
#include "core/Input.h"
#include "canvas/Canvas2D.h"
#include "scene/2d/Drawable2D.h"
#include "scene/Scene.h"

#include <functional>

class Engine : public Object {

	CLASS(Engine, Object);

	public:
		Engine();
		virtual ~Engine() = default;

	// Scenes
	private:
		std::size_t current_scene = 0;
		std::vector <Scene> scenes;

	public:
		void add_scene(Scene &scene);
		Scene & get_scene(std::size_t position);

		void set_current_scene(std::size_t position);
		Scene & get_current_scene();

	// Input
	private:
		Input &input;

	public:
		Input & get_input();

	private:
		sf::Clock loop_timer;
		float fps;

	public:
		void launch();
		float get_fps();
};

#endif