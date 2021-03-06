/* Player.cpp ¬ ASCIIEngine ¬ 7Games
	Created: 09/03/21
	Last Edited: 24/04/21
*/
#include "Player.hpp"

std::string walkToChar = ".";

int ASCIIEngine::Player::UpdatePos(int playerPos, int mapHorLength, std::string map) {
    actionPressed = false;
    char moveKey = in.getKeyPress();
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
        case 'e':
            actionPressed = true;
            break;
        default:
            break;
    }

    return playerPos;
}

std::string ASCIIEngine::Player::getOnTopChar() {
    return walkToChar;
}

void ASCIIEngine::Player::setOnTopChar(std::string c) {
    walkToChar = c;
}