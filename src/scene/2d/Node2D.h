#ifndef NODE2D_H
#define NODE2D_H

#include "scene/Node.h"
#include "core/math/Point2.h"

class Node2D : public Node {

	public:

		Node2D();

		void setPosition(Point2 p);
		Point2 getPosition();

		void move(Point2 p);

	protected:
		Point2 position;
};

#endif // NODE2D_H
