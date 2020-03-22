#ifndef NODE_H
#define NODE_H

#include <vector>
#include <map>
#include <iterator>

#include "core/EventHandler.h"
#include "core/Nameable.h"

#define NODE_ADD_CHILD_THIS_EXCEPTION "Tried to add node object itself as a child"

class Node;

typedef std::vector <Node *> NodeChildren;
typedef std::map <StringName, Node *> NodeChildrenMap;

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
        NodeChildrenMap getChildrenMap();
        Node * getParent();

    protected:

        // Children
        NodeChildren children;
        Node * parent;
};

#endif // NODE_H
