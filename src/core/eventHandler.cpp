#include "core/EventHandler.h"

EventHandler::EventHandler(){}
EventHandler::~EventHandler(){}

void EventHandler::on(std::string name, EventMethod method){
	events[name] = method;
}

void EventHandler::trigger(std::string name){
	auto itr = events.find(name);
	if(itr == events.end()){
		throw "Event " + name + " does not exist";
	}
	(*itr->second)();
}
