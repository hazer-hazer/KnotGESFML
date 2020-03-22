#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "scene/2d/Line2D.h"
#include "canvas/Canvas2D.h"
#include "core/Color.h"

int main(){
	Canvas2D canvas({ 1080, 720 }, "TITLE");

	Color color(0x000000);

	Line2D * line = new Line2D(Point2(0, 0), Point2(100, 100));

	while(canvas.isOpen()){
		canvas.clear(color.toSfColor());
		canvas.handleEvents();
		line->draw(canvas);
		canvas.display();
	}
}