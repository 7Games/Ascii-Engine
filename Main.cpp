/* Main.cpp ¬ GamerTime ¬ 7Games
	Created: 09/03/20
	Last Edited: 13/03/20
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Player.hpp"
#include "MapLoader.hpp"

std::string map;
int playerPos;
int mapHorLength;

int main(){
    loadMap("data/1.json");

    map = jsonGetStringData("map");
    playerPos = jsonGetIntData("playerStartPos");
    mapHorLength = jsonGetIntData("mapHorLength");

    while ( map.find ("n") != std::string::npos ) {
        map.replace(map.find("n"), 1, "\n");
    }

    while(true) {
        system("cls");
        map = map.replace(playerPos, 1, "@");
        std::cout << map;
        map = map.replace((playerPos), 1, ".");
        playerPos = UpdatePos(playerPos, mapHorLength, map);
    }
}