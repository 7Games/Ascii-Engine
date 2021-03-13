/* Player.cpp ¬ GamerTime ¬ 7Games
	Created: 09/03/20
	Last Edited: 13/03/20
*/
#include "Input.hpp"
#include "Player.hpp"

std::string walkToChar = ".";

int UpdatePos(int playerPos, int mapHorLength, std::string map) {
    char moveKey = getKeyPress();
    
    switch (moveKey) {
        case 'w':
            if(map.at(playerPos-mapHorLength) != '#'){
                walkToChar = map.at(playerPos-mapHorLength);
                playerPos = playerPos - mapHorLength;
            }
            break;
        case 's':
            if(map.at(playerPos+mapHorLength) != '#'){
                walkToChar = map.at(playerPos+mapHorLength);
                playerPos = playerPos + mapHorLength;
            }
            break;
        case 'a':
            if(map.at(playerPos-1) != '#'){
                walkToChar = map.at(playerPos-1);
                playerPos = playerPos - 1;
            }
            break;
        case 'd':
            if(map.at(playerPos+1) != '#'){
                walkToChar = map.at(playerPos+1);
                playerPos = playerPos + 1;
            }
            break;
        
        default:
            break;
    }

    return playerPos;
}

std::string getOnTopChar() {
    return walkToChar;
}

void setOnTopChar(std::string c) {
    walkToChar = c;
}