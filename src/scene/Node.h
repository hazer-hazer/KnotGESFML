#include <vector>
#include <map>
#include <iterator>

#ifndef NODE_H
#define NODE_H

#include "core/EventHandler.h"
#include "core/Nameable.h"

#define NODE_ADD_CHILD_THIS_EXCEPTION "Tried to add node object itself as a child"

class Node;

typedef std::map <StringName, Node *> NodeChildren;
typedef std::vector <Node *> NodeChildrenArray;

class Node : public Nameable,
			 public EventHandler {

    public:

        Node();
        Node(StringName);

        // Children
        void addChild(Node * child);
        Node * findChild(std::string path);
        Node * findChild();
        NodeChildren getChildren();
        NodeChildrenArray getChildrenArray();
        Node * getParent();

    protected:

        // Children
        NodeChildren children;
        Node * parent;
};

#endif // NODE_H
