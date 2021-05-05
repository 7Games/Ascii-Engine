/* JSONLoader.cpp ¬ ASCIIEngine ¬ 7Games
	Created: 13/03/21
	Last Edited: 24/04/21
*/
#include "JSONLoader.hpp"

std::ifstream i;

json j;

void ASCIIEngine::JSONLoader::loadJSON(std::string name) {
    i.open(name);
    j = json::parse(i);
    i.close();
}
void ASCIIEngine::JSONLoader::unloadJSON() {
    j.clear();
}

std::string ASCIIEngine::JSONLoader::jsonGetStringData(std::string data) {
    return j.at(data);
}

int ASCIIEngine::JSONLoader::jsonGetIntData(std::string data) {
    int i = j.at(data);
    return i;
}

std::vector<int> ASCIIEngine::JSONLoader::jsonGetArrayInt(std::string data) {
	return j[data].get<std::vector<int>>();
}

std::vector<std::string> ASCIIEngine::JSONLoader::jsonGetArrayString(std::string data) {
	return j[data].get<std::vector<std::string>>();
}