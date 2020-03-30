#ifndef LABEL_H
#define LABEL_H

#include <SFML/Graphics.hpp>
#include "core/Color.h"
#include "scene/2d/Drawable2D.h"
#include "canvas/Canvas2D.h"
#include "core/ResourceHolder.h"

#define DEFAULT_FONT_SIZE 20

class Label : public Drawable2D {

	CLASS(Label, Drawable2D);

	public:
		Label();
		virtual ~Label() = default;

		virtual void onready();
		virtual void onprocess(float delta);

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	private:
		sf::Text label;

	public:
		void set_text(std::string text);
		std::string get_text();

		void set_font(sf::Font &font);
		sf::Font & get_font();

		void set_font_size(unsigned int size);
		unsigned int get_font_size();

		void set_color(const Color &color);
		const Color & get_color();

		void set_style(uint32_t style = sf::Text::Regular);
		uint32_t get_style();
};

#endif