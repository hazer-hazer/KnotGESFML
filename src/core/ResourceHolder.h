#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <SFML/Graphics.hpp>

#include "core/ResourceManager.h"

class ResourceHolder : public Object {
	public:

		static ResourceManager <sf::Texture> textures;
		static ResourceManager <sf::Font> fonts;
};

#endif