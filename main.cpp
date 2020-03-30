#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "canvas/Canvas2D.h"
#include "core/Color.h"
#include "core/Input.h"
#include "core/ResourceHolder.h"
#include "scene/Node.h"
#include "core/Object.h"
#include "scene/2d/Sprite.h"
#include "scene/2d/Label.h"
#include "core/Engine.h"
#include "scene/2d/Particles2D.h"
#include "scene/Scene.h"

using std::cout;
using std::endl;

int main(){
	try{
		Engine engine;

		Node * root = new Node;

		Particles2D * particles = new Particles2D();

		particles->set_amount(100);
		particles->set_color(Color::RED);
		particles->set_shape(Particles2D::CIRCLE);
		particles->setPosition(540, 360);
		particles->set_gravity(2.5f);
		particles->set_texture(ResourceHolder::textures.load("star"));
		particles->set_size(25);
		particles->set_speed(100.f);

		root->add_child(particles);

		// FPS Meter
		Label * fpsMeter = new Label;
		fpsMeter->setPosition(0, 0);
		fpsMeter->set_color(Color::CYAN);
		fpsMeter->set_font(ResourceHolder::fonts.load("roboto"));

		fpsMeter->set_process([&engine, &fpsMeter](float delta){
			fpsMeter->set_text(std::to_string((int)engine.get_fps()));
		});

		root->add_child(fpsMeter);

		Scene scene;
		scene.set_root(root);

		engine.add_scene(scene);

		engine.get_input().on("mouse_moved", [&engine, &particles](){
			particles->setPosition(engine.get_input().get_mouse_position());
		});

		engine.launch();

	}catch(const char * message){
		std::cerr << message << std::endl;
	}catch(std::string message){
		std::cerr << message << std::endl;
	}

	return 0;
}