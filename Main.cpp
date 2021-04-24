/* Main.cpp ¬ ASCIIEngine ¬ 7Games
	Created: 09/03/21
	Last Edited: 24/04/21
*/
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <algorithm>
#include <vector>
#include "Player.hpp"
#include "Input.hpp"
#include "JSONLoader.hpp"
#include "Misc.hpp"

using jsonloader = ASCIIEngine::JSONLoader;
using player = ASCIIEngine::Player;
using input = ASCIIEngine::Input;

enum GameState {
    title,
    game
};

std::string versionNumber = "0.9a";

std::string map;
std::string gameTitle;
char titleKeyPress;
bool levelEnded;
int mapHorLength;
int playerPos;
int playerExit=0;
bool running = true;

jsonloader jl;
player p;
input in;
GameState state = title;

std::vector<std::string> nextMap;
std::vector<int> levelEnd;
std::vector<int> playerStartNextMap;

void ClearScreen() {
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void loadNextLevel() {
    if(levelEnded) {
        jl.loadJSON(nextMap[playerExit]);

        map = jl.jsonGetStringData("map");
        mapHorLength = jl.jsonGetIntData("mapHorLength");
        levelEnd = jl.jsonGetArrayInt("levelEnd");

        while ( map.find ("n") != std::string::npos ) {
            map.replace(map.find("n"), 1, "\n");
        }
        levelEnded = false;
    }
}
void updatePlayer(){
    //Draw Map and Player
    map = map.replace(playerPos, 1, "@");
    std::cout << map;
    map = map.replace((playerPos), 1, p.getOnTopChar());
                
    //Player Movement
    playerPos = p.UpdatePos(playerPos, mapHorLength, map);
}

int main(){
	//Checks if the data folder is there
	std::ifstream exists("./data/info.json");
    if(exists.good()){
		levelEnded = true;
		//Loads the info file. Sets the title bar text, main menu text and first map
		jl.loadJSON("./data/info.json");
		gameTitle = jl.jsonGetStringData("gameTitle");
		while ( gameTitle.find ("`") != std::string::npos ) {
			gameTitle.replace(gameTitle.find("`"), 1, "\n");
		}
		nextMap.insert(end(nextMap), jl.jsonGetStringData("firstMap"));
		playerPos = jl.jsonGetIntData("playerStartPos");
		const char * c = jl.jsonGetStringData("programTitle").c_str();
		jl.unloadJSON();
		//Sets the title
		SetConsoleTitleA(c);

		while(running) {
			//Checks if the game is in the title or game state
			switch(state){
				case title:
					std::cout<< gameTitle<<"\n\n\n"<<versionNumber<<"\n";
					titleKeyPress = in.getKeyPress();
					if(titleKeyPress=='1'){
						state=game;
					}
					if(titleKeyPress=='2'){
						running = false;
					}
					break;
				case game:
					//Check if the player is at the end of the level
					for(int i = 0; i < levelEnd.size(); i++){
						if(levelEnded == false && playerPos == levelEnd[i]) {
							system("cls");
							playerExit = i;
							p.setOnTopChar(".");
							nextMap = jl.jsonGetArrayString("nextMap");
							playerStartNextMap = jl.jsonGetArrayInt("playerStartNextMap");
							playerPos = playerStartNextMap[i];
							levelEnded = true;
							jl.unloadJSON();
							map = "";
						}
					}
					
					loadNextLevel();
					ClearScreen();
					updatePlayer();
					break;
			}
			
		}
	} else {
		SetConsoleTitleA("Error");
		std::cout << "Data Folder not found! Press any key to exit.";
		_getch();
	}
    
}
