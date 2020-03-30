#include "core/Object.h"

Object::Object(){
}

void Object::error(std::string message){
	message = "\e[0;31m" + message;
	print(message, true);
}