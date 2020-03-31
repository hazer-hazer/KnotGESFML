#ifndef PROJECTSETTINGS_H
#define PROJECTSETTINGS_H

#include "project/FileHandler.h"

#define KNOT_PROJECT_FILENAME "project"

class ProjectSettings : public FileHandler {

	CLASS(ProjectSettings, FileHandler);

	public:
		ProjectSettings(std::string dir);
		virtual ~ProjectSettings() = default;

	GETSET(std::string, project_name);
};

#endif