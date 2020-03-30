/**
 * Node is a part of scene tree.
 */

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

typedef std::function <void(void)> ReadyFunction;
typedef std::function <void(float delta)> ProcessFunction;

class Node : public Object {
	
	CLASS(Node, Object);

	public:
		Node();
		virtual ~Node() = default;

	// TODO: Make onready and onprocess events with emmiting in game cycle

	// Ready
	public:
		virtual void onready();
		void set_ready(ReadyFunction ready);
		void ready();

	private:
		ReadyFunction _ready;

	// Process
	public:
		virtual void onprocess(float delta);
		void set_process(ProcessFunction process);
		void process();

	private:
		ProcessFunction _process;
		sf::Clock process_timer;

	// Children
	public:
		NodeChildren get_children();

		void add_child(Node * child);

		Node * find_child();
		Node * find_child(std::string path);

		NodeChildrenMap get_children_map();
		void each_child(std::function <void(Node *)> forEach);

	private:
		NodeChildren children;


	// Parent
	public:
		Node * get_parent();
		void set_parent(Node * parent);

	private:
		Node * parent;
	
	// Name
	public:
		void set_name(std::string name);
		void set_name();
		std::string get_name();
	
	private:
		std::string name;

		bool has_child_with_name(std::string name);

};

#endif // NODE_H
