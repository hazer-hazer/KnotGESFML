#include "core/EventHandler.h"

EventHandler::EventHandler(){}
EventHandler::~EventHandler(){}

void EventHandler::on(std::string name, EventMethod method){
	events[name].push_back(method);
}

void EventHandler::emit(std::string name){
	auto itr = events.find(name);
	if(itr == events.end()){
		throw print("Event " + name + " does not exist", false);
	}
	if(events[name].size() == 0){
		return;
	}
	for(auto ev : itr->second){
		ev();
	}
}

void EventHandler::clearEvents(std::string name){
	events[name].clear();
}

bool EventHandler::eventExists(std::string name){
	return events.find(name) != events.end();
}