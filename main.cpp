#include "src/nodes/Node.h"

int main(){
    Node * c = new Node();
	Node * a = new Node();

	c->addChild(a);

	for(Node * n : c->getChildren()){
		n->test();
	}

    return 0;
}
