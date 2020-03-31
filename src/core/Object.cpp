#include "core/Object.h"

Object::Object(){
}

void Object::error(std::string message, bool thr){
	message = "\e[0;31m" + message;
	if(thr){
		throw print(message, false);
	}else{
		print(message);
	}
}