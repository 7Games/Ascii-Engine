#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Player.hpp"

std::string map;
int playerPos;
int mapHorLength;

int main(){
    std::string myText;
    std::fstream myfile("data/1.map", std::ios_base::in);
    std::getline (myfile, myText);
    map = myText;
    std::getline (myfile, myText);
    playerPos = std::stoi(myText);
    std::getline (myfile, myText);
    mapHorLength = std::stoi(myText);
    myfile.close();

    while ( map.find ("n") != std::string::npos ) {
        map.replace(map.find("n"), 1, "\n");
    }   

    while(true) {
        system("cls");
        map = map.replace(playerPos, 1, "@");
        std::cout << map;
        map = map.replace(playerPos, 1, ".");
        playerPos = UpdatePos(playerPos, mapHorLength, map);
    }
}