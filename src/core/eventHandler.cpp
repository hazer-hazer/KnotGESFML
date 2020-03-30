#include "core/EventHandler.h"

EventHandler::EventHandler(){
	events.clear();
}
EventHandler::~EventHandler(){}

void EventHandler::on(std::string name, EventMethod method){
	events[name].push_back(method);
}

void EventHandler::emit(std::string name){
	auto itr = events.find(name);
	if(itr == events.end()){
		// If there's no events yet then just return.
		// Maybe it will be remade when I'll create MessageBus or whatevert
		return;
	}
	for(auto ev : itr->second){
		ev();
	}
}

void EventHandler::clear_events(std::string name){
	events[name].clear();
}

bool EventHandler::event_exists(std::string name){
	return events.find(name) != events.end();
}