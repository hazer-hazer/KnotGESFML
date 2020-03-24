#ifndef LABEL_H
#define LABEL_H

#include <SFML/Graphics.hpp>
#include "core/Color.h"
#include "scene/2d/Drawable2D.h"
#include "canvas/Canvas2D.h"

#define DEFAULT_FONT_SIZE 20

class Label : public Drawable2D {
	public:
		Label(){};
		Label(std::string str, sf::Font &font, unsigned int fontSize = DEFAULT_FONT_SIZE)
		: text(str, font, fontSize){};

		virtual ~Label() = default;

		void setString(std::string str);
		void setFont(sf::Font &font);
		void setFontSize(unsigned int size = DEFAULT_FONT_SIZE);
		void setStyle(uint32_t style = sf::Text::Regular);
		void setColor(Color c);

		void draw(Canvas2D &canvas);

	private:
		sf::Text text;
};

#endif