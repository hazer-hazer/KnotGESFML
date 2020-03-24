#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <string>
#include <map>
#include <vector>
#include <functional>

#include "core/Object.h"

typedef std::function<void()> EventMethod;

typedef std::map <std::string, std::vector <EventMethod>> EventStack;

class EventHandler : public Object {
	public:
		EventHandler();
		virtual ~EventHandler();

		void on(std::string name, EventMethod method);
		void emit(std::string name);
		void remove(std::string name);

	private:
		EventStack events;
};

#endif // EVENTHANDLER_H
