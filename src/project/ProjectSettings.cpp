#include "project/ProjectSettings.h"

ProjectSettings::ProjectSettings(std::string dir)
: FileHandler(dir + "/" + KNOT_PROJECT_FILENAME) {

	set_project_name( get_var("project")["name"] );

}