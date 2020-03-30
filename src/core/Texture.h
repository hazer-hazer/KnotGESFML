#ifndef TEXTURE_H
#define TEXTURE_H

class Texture {
	public:
		Texture(){};
		Texture(Texture & texture){};

		virtual ~Texture() = default;
};

#endif