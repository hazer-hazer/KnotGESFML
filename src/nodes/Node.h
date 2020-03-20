#include <vector>

#include <iostream>

class Node;

typedef std::vector <Node *> NodeChildren;

class Node {
    public:
        Node();
        ~Node();

        void test(){
			std::cout << "Node" << std::endl;
        }

        void addChild(Node * child);

        NodeChildren getChildren();
    private:
        NodeChildren children;
};
