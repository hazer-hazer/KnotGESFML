#include <vector>
#include <map>
#include <iterator>

#include "eventHandler.h"
#include "nameable.h"

#ifndef NODE_H
#define NODE_H

#define NODE_ADD_CHILD_THIS_EXCEPTION "Tried to add node object itself as a child"

class Node;

typedef std::map <StringName, Node *> NodeChildren;
typedef std::vector <Node *> NodeChildrenArray;

class Node : public Nameable,
			 public EventHandler {
    public:
        Node();
        Node(StringName);
        virtual ~Node();

        // Children
        void addChild(Node * child);
        NodeChildren getChildren();
        NodeChildrenArray getChildrenArray();
        Node * getParent();

    private:

        // Children
        NodeChildren children;
        Node * parent;
};

#endif // NODE_H
