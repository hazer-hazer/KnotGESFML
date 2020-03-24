#include "core/EventHandler.h"

EventHandler::EventHandler(){}
EventHandler::~EventHandler(){}

void EventHandler::on(std::string name, EventMethod method){
	events[name].push_back(method);
}

void EventHandler::emit(std::string name){
	auto itr = events.find(name);
	if(itr == events.end()){
		throw "Event " + name + " does not exist";
	}
	for(auto ev : itr->second){
		ev();
	}
}

void EventHandler::remove(std::string name){
	events[name].clear();
}