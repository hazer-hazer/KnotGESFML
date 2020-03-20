#include "Node.h"

Node::Node(){

}

Node::~Node(){}


void Node::addChild(Node * child){
    children.push_back(child);
}

NodeChildren Node::getChildren(){
	return children;
}
