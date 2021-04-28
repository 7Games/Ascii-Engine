/* JSONLoader.hpp ¬ ASCIIEngine ¬ 7Games
	Created: 13/03/20
	Last Edited: 31/03/20
*/
#ifndef JSONLOADER_H
#define JSONLOADER_H

#include "json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

using json = nlohmann::json;

namespace ASCIIEngine {
	class JSONLoader {
	public:
		void loadJSON(std::string name);
		void unloadJSON();

		std::string jsonGetStringData(std::string data);
		int jsonGetIntData(std::string data);
		std::vector<int> jsonGetArrayInt(std::string data);
		std::vector<std::string> jsonGetArrayString(std::string data);
	};
}

#endif //JSONLOADER_H