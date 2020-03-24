#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <unordered_map>

#include "core/Object.h"

/**
 * Change to storing special Resource class as template typename
 * to make possible using images, fonts and etc. with different extension
*/

template <typename Resource>
class ResourceManager : public Object {
	public:
		ResourceManager(const std::string & dir, const std::string & ext)
		: directory(dir), extension("." + ext){
			setName("ResourceManager");
		};

		Resource & load(const std::string & name){
			if(!exists(name)){
				add(name);
			}

			return resources.at(name);
		}

		bool exists(const std::string & name) const {
			return resources.find(name) != resources.end();
		}

		void add(const std::string & name){
			Resource res;
			std::string path = getFullPath(name);
			if(!res.loadFromFile(path)) {
				throw print("Failed to load file by path " + path, false);
				// Resource fail;
				// fail.loadFromFile(m_folder + "_fail_" + m_extention);
				// m_resources.insert(std::make_pair(name, fail));
			}else {
				resources.insert(std::make_pair(name, res));
			}
		}

	private:
		std::string getFullPath(const std::string & name){
			return directory + "/" + name + extension;
		}

		const std::string directory;
		const std::string extension;

		std::unordered_map <std::string, Resource> resources;
};

#endif