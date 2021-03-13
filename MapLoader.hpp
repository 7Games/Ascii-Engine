/* MapLoader.hpp ¬ GamerTime ¬ 7Games
	Created: 13/03/20
	Last Edited: 13/03/20
*/
#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "json.hpp"
#include <iostream>
#include <fstream>
#include <string.h>

using json = nlohmann::json;

void loadMap(std::string name);

std::string jsonGetStringData(std::string data);
int jsonGetIntData(std::string data);

#endif //PLAYER_H