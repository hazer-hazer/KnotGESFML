#include "Node.h"

Node::Node(){
	setName();
}

Node::Node(StringName name){
	setName(name);
}

// Insert a child as a pair of its name and object
void Node::addChild(Node * child){
	if(this == child){
		throw NODE_ADD_CHILD_THIS_EXCEPTION;
	}
    child->parent = this;
    children.insert(std::pair <StringName, Node *> (child->getName(), child));
}

Node * Node::findChild(){
	return this;
}

Node * Node::findChild(std::string path){
	if(path.size() == 0 || path == "/"){
		return findChild();
	}
	std::string child = path.substr(0, path.find('/'));
	if(children[child]){
		throw "Node " + child + " was not found in Node " + name;
	}
	return children[child]->findChild( path.substr(path.find('/') + 1, path.size() - 1) );
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
