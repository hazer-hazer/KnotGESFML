#include "src/nodes/Node.h"

#include <iostream>


int main(){
	try{
		Node * a = new Node("A");
		Node * b = new Node("B");

		a->on("event", [](){
			std::cout << "EVENT" << std::endl;
		});

		a->trigger("event");

	}catch(const char * message){
		std::cout << message << std::endl;
	}


    return 0;
}
