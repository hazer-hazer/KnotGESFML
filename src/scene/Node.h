#ifndef NODE_H
#define NODE_H

#include <vector>
#include <map>
#include <iterator>
#include <functional>

#include <SFML/Graphics.hpp>

#include "core/Object.h"

#define NODE_ADD_CHILD_THIS_EXCEPTION "Tried to add node object itself as a child"

class Node;

typedef std::vector <Node *> NodeChildren;
typedef std::map <std::string, Node *> NodeChildrenMap;

class Node : public Object {

    public:

        Node() : Object(){};
        Node(std::string name) : Object(name){};

        virtual ~Node() = default;

        void update();

        void _process(std::function <void(float delta)> process);

        // Children
        void addChild(Node * child);
        Node * findChild(std::string path);
        Node * findChild();
        NodeChildren getChildren();
        NodeChildrenMap getChildrenMap();
        Node * getParent();
        void eachChild(std::function <void(Node *)> forEach);

    protected:
        sf::Clock processTimer;

        std::function <void(float delta)> process;

        // Children
        NodeChildren children;
        Node * parent;
};

#endif // NODE_H
