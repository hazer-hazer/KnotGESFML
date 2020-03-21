#include <string>
#include <map>

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

typedef void (*EventMethod)(void);

typedef std::map <std::string, EventMethod> EventStack;

class EventHandler{
	public:
		EventHandler();
		virtual ~EventHandler();

		void on(std::string name, EventMethod method);
		void trigger(std::string name);

	private:
		EventStack events;
};

#endif // EVENTHANDLER_H
