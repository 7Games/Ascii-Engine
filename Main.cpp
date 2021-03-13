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
std::string nextMap = "data/1.json";
bool levelEnded;
int levelEnd;

int main(){
    levelEnded = true;
    while(true) {
        if(levelEnded == false && playerPos == levelEnd) {
            setOnTopChar(".");
            nextMap = jsonGetStringData("nextMap");
            levelEnded = true;
            unloadMap();
        }
        if(levelEnded) {
            loadMap(nextMap);

            map = jsonGetStringData("map");
            playerPos = jsonGetIntData("playerStartPos");
            mapHorLength = jsonGetIntData("mapHorLength");
            levelEnd = jsonGetIntData("levelEnd");

            while ( map.find ("n") != std::string::npos ) {
                map.replace(map.find("n"), 1, "\n");
            }
            levelEnded = false;
        }

        system("cls");
        map = map.replace(playerPos, 1, "@");
        std::cout << map;
        std::cout << "Player Position: " << playerPos;
        map = map.replace((playerPos), 1, getOnTopChar());
        playerPos = UpdatePos(playerPos, mapHorLength, map);
    }
}
