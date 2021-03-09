#include "Input.hpp"
#include "Player.hpp"

int UpdatePos(int playerPos, int mapHorLength, std::string map) {
    char moveKey = getKeyPress();
    
    switch (moveKey) {
        case 'w':
            if(map.at(playerPos-mapHorLength) != '#'){
                playerPos = playerPos - mapHorLength;
            }
            break;
        case 's':
            if(map.at(playerPos+mapHorLength) != '#'){
                playerPos = playerPos + mapHorLength;
            }
            break;
        case 'a':
            if(map.at(playerPos-1) != '#'){
                playerPos = playerPos - 1;
            }
            break;
        case 'd':
            if(map.at(playerPos+1) != '#'){
                playerPos = playerPos + 1;
            }
            break;
        
        default:
            break;
    }

    return playerPos;
}