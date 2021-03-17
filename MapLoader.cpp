/* MapLoader.cpp ¬ GamerTime ¬ 7Games
	Created: 13/03/20
	Last Edited: 17/03/20
*/
#include "MapLoader.hpp"

std::ifstream i;

json j;

void loadMap(std::string name) {
    i.open(name);
    j = json::parse(i);
    i.close();
}
void unloadMap() {
    j.clear();
}

std::string jsonGetStringData(std::string data) {
    return j.at(data);
}

int jsonGetIntData(std::string data) {
    int i = j.at(data);
    return i;
}
