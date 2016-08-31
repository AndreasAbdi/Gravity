#pragma once 
#include <map>
#include <string>
#include "boost/any.hpp"

namespace Gravity {
	class Configurations {
	private:
		std::map<std::string, boost::any> keyToConfig;
	public:
		void readConfigsFromFile(const std::string fileLocation);
		void addConfig(const std::string key, const boost::any value);
		void deleteConfig(const std::string key);
		bool getRawValue(const std::string key, boost::any &value);
		bool writeToFile(const std::string fileLocation);
		template<typename T> inline bool Configurations::getValue(const std::string key, T & value) {
			auto keyIterator = keyToConfig.find(key);
			if (keyIterator == keyToConfig.end()) {
				return false;
			}
			auto foundValue = ((*keyIterator).second);

			if (foundValue.type() != typeid(T)) {
				return false;
			}
			value = boost::any_cast<T>(foundValue);
			return true;
		}

	};
}
