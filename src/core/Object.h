#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include "core/EventHandler.h"

/**
 * Object is the main class that operates with basic
 * class parameters.
 * Object has name. Name is 
 */

class Object : public EventHandler {

	#define CLASS(m_class, m_parent) \
	public: \
		std::string get_class(){ \
			return #m_class; \
		} \
		std::string get_parent_class(){ \
			return #m_parent; \
		} \
		std::string print(std::string message, bool print = true){ \
			message = std::string("[")+ #m_class +"]: " + message; \
			if(print){ \
				std::cout << message << std::endl; \
			} \
			return message; \
		}

	#define GETSET(type, varname) \
	public: \
		void set_##varname(type __value){ varname = __value; }; \
		type get_##varname() const { return varname; } \
	private: \
		type varname;

	#define GETSETD(type, varname, default_val) \
	public: \
		void set_##varname(type __value){ varname = __value; }; \
		type get_##varname() const { return varname; } \
	private: \
		type varname = default_val;

	CLASS(Object, None);

	public:
		Object();
		virtual ~Object() = default;

		void error(std::string message, bool thr = true);

};

#endif