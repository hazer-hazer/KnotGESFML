#include "project/FileHandler.h"

FileHandler::FileHandler(const std::string & path){
	this->path = path;

	lua.open_libraries(sol::lib::base);

	auto result = lua.safe_script_file(path, sol::script_pass_on_error);

	if(!result.valid()){
		sol::error err = result;
		error(std::string(err.what()));
	}
}