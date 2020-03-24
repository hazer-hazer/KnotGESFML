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

int main(){

	try{

		Canvas2D canvas({ 1300, 750 }, "TITLE");

		Sprite * sprite = new Sprite("image");

		Input input(canvas.getWindow());

		// int x = 0, y = 0;

		// input.on("keyPressedA", [&sprite, &x](){
		// 	x = -1;
		// });
		// input.on("keyPressedD", [&sprite, &x](){
		// 	x = 1;
		// });
		// input.on("keyPressedW", [&sprite, &y](){
		// 	y = -1;
		// });
		// input.on("keyPressedS", [&sprite, &y](){
		// 	y = 1;
		// });

		// input.on("keyReleasedA", [&sprite, &x](){
		// 	x = 0;
		// });
		// input.on("keyReleasedD", [&sprite, &x](){
		// 	x = 0;
		// });
		// input.on("keyReleasedW", [&sprite, &y](){
		// 	y = 0;
		// });
		// input.on("keyReleasedS", [&sprite, &y](){
		// 	y = 0;
		// });

		Label * label = new Label("FPS", ResourceHolder::fonts.load("roboto"), 32);
		label->setColor(Color::RED);

		input.on("mouseMoved", [&sprite, &input](){
			sprite->setPosition(input.getMousePosition());
		});

		while(canvas.isOpen()){
			canvas.clear();

			input.pollEvents();

			sprite->draw(canvas);
			
			label->draw(canvas);

			canvas.display();
		}
	}catch(const char * message){
		std::cout << message << std::endl;
	}
}