#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include "project/c_assert.h"
#include "core/Object.h"

class FileHandler : public Object {

	CLASS(FileHandler, Object);

	// Path
	GETSET(std::string, path);

	public:
		FileHandler(const std::string & path);
		virtual ~FileHandler() = default;

	private:
		sol::state lua;

	// Get var
	public:
		template <typename T>
		T get_var(std::string varname){
			return lua.get<T>(varname);
		}

};

#endif