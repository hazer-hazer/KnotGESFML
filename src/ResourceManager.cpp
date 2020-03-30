#include "core/ResourceManager.h"

ResourceManager(const std::string & dir, const std::string & ext) : directory(dir), extension("." + ext){

}

std::string ResourceManager::get_full_path(const std::string & name){
	return directory + "/" + name + extension;
}

Resource & ResourceManager::load(const std::string & name){
	if(!exists(name)){
		add(name);
	}

	return resources.at(name);
}

bool ResourceManager::exists(const std::string & name) const {
	return resources.find(name) != resources.end();
}

void ResourceManager::add(const std::string & name){
	Resource res;
	std::string path = get_full_path(name);
	if(!res.loadFromFile(path)) {
		throw print("Failed to load file by path " + path, false);
		// Resource fail;
		// fail.loadFromFile(m_folder + "_fail_" + m_extention);
		// m_resources.insert(std::make_pair(name, fail));
	}else {
		print(path + " loaded");
		resources.insert(std::make_pair(name, res));
	}
}