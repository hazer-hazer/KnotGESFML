#include "nameable.h"

int Nameable::lastAutoGenerated = 0;

StringName Nameable::getName(){
	return name;
}

void Nameable::setName(StringName name){
	this->name = name;
}

void Nameable::setName(){
    setName(std::to_string(++Nameable::lastAutoGenerated));
}