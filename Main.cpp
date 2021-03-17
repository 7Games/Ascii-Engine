/* Main.cpp ¬ GamerTime ¬ 7Games
	Created: 09/03/20
	Last Edited: 17/03/20
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Player.hpp"
#include "MapLoader.hpp"
#include "Misc.hpp"

std::string nextMap = "data/1.json";
std::string map;

bool levelEnded;
bool levelHasPreferedLocation;

int mapHorLength;
int playerPos;
int levelEnd;

int main(){
    levelEnded = true;
    while(true) {
        //Check if the player is at the end of the level
        if(levelEnded == false && playerPos == levelEnd) {
            setOnTopChar(".");
            nextMap = jsonGetStringData("nextMap");
            levelEnded = true;
            unloadMap();
            map = "";
        }
        //Load Next Map
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

        //Clear Console Window
        system("cls");
        //Draw Map and Player
        map = map.replace(playerPos, 1, "@");
        std::cout << map;
        map = map.replace((playerPos), 1, getOnTopChar());
        
        //UI
        std::cout << "Player Position: " << playerPos;
        //Player Movement
        playerPos = UpdatePos(playerPos, mapHorLength, map);
    }
}
