#include <iostream>
#include <string.h>
#include "Player.hpp"

std::string map = "########\n#......#\n#......#\n########\n";
int playerPos = 12;

int main(){
    while(true) {
        system("cls");
        map = map.replace(playerPos, 1, "@");
        std::cout << map;
        map = map.replace(playerPos, 1, ".");
        playerPos = UpdatePos(playerPos, 9, map);
    }
}
//test