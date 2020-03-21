#include "Node.h"

Node::Node(){
	setName();
}

Node::Node(StringName name){
	setName(name);
}

Node::~Node(){}

// Insert a child as a pair of its name and object
void Node::addChild(Node * child){
	if(this == child){
		throw NODE_ADD_CHILD_THIS_EXCEPTION;
	}
    child->parent = this;
    children.insert(std::pair <StringName, Node *> (child->getName(), child));
}

// Get Children as map <string, Node *>
NodeChildren Node::getChildren(){
	return children;
}

// Get Children as vector
NodeChildrenArray Node::getChildrenArray(){
    NodeChildrenArray chidlrenArray;
    NodeChildren::iterator iterator;
    for(iterator = children.begin(); iterator != children.end(); iterator++){
        chidlrenArray.push_back(iterator->second);
    }
    return chidlrenArray;
}
