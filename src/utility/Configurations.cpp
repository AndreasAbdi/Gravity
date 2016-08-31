#include "Configurations.h"

namespace Gravity {


	void Configurations::addConfig(std::string key, boost::any value) {
		this->keyToConfig[key] = value;
	}

	void Configurations::deleteConfig(std::string key) {
		auto iter = keyToConfig.find(key);
		if (iter != keyToConfig.end()) {
			this->keyToConfig.erase(key);
		}
	}

	bool Configurations::getRawValue(const std::string key, boost::any &value) {
		auto keyIterator = keyToConfig.find(key);
		if (keyIterator != keyToConfig.end()) {
			value = ((*keyIterator).second);
			return true;
		}
		return false;
	}

	void Configurations::readConfigsFromFile(std::string fileLocation) {
		//TODO
		//TODO: get the boost ini parse and shove configs in an ini. 
	}

	bool Configurations::writeToFile(const std::string fileLocation) {
		//TODO
		return false;
	}

}