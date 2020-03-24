#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

class Object {
	public:
		Object();
		Object(std::string name);

        virtual ~Object() = default;

		std::string getName();
		void setName(std::string name);
		void setName();

		static int lastAutoGeneratedName;

	protected:
		std::string name;
		const char * print(std::string message, bool print = true);
};

#endif