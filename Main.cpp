/* Main.cpp ¬ ASCIIEngine ¬ 7Games
	Created: 09/03/21
	Last Edited: 27/04/21
*/
#include "Misc.hpp"

using jsonloader = ASCIIEngine::JSONLoader;
using player = ASCIIEngine::Player;
using input = ASCIIEngine::Input;

enum GameState {
    title,
    game
};

std::string versionNumber = "0.9a";
bool debugMode = true;

std::string map;
std::string talkText;
std::string gameTitle;


char titleKeyPress;
bool levelEnded;
int mapHorLength;
int mapTotalLength;
int playerPos;
int playerExit=0;
bool running = true;
bool talking = false;

jsonloader jl;
player p;
input in;
GameState state = title;

std::vector<std::string> nextMap;
std::vector<std::string> nextTrigger;
std::vector<std::string> textTrigger;
std::vector<std::string> triggerType;
std::vector<std::string> triggerChangeTo;
std::vector<int> triggerChangeAt;
std::vector<int> triggerTalkPosition;
std::vector<int> triggerChangePosition;
std::vector<int> levelEnd;
std::vector<int> playerStartNextMap;

void ClearScreen() {
	if(p.actionPressed){
		system("cls");
	}
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void loadNextLevel() {
    if(levelEnded) {
        jl.loadJSON(nextMap[playerExit]);

        map             = jl.jsonGetStringData("map");
        mapHorLength    = jl.jsonGetIntData("mapHorLength");
        levelEnd        = jl.jsonGetArrayInt("levelEnd");

		jl.loadJSON(nextTrigger[playerExit]);

		triggerTalkPosition   = jl.jsonGetArrayInt("triggerTalkPos");
		triggerChangePosition = jl.jsonGetArrayInt("triggerChangePos");
		triggerType           = jl.jsonGetArrayString("triggerType");
		textTrigger           = jl.jsonGetArrayString("triggerTalk");
		triggerChangeAt       = jl.jsonGetArrayInt("triggerChangeAt");
		triggerChangeTo       = jl.jsonGetArrayString("triggerChangeTo"); 

        while ( map.find ("n") != std::string::npos ) {
            map.replace(map.find("n"), 1, "\n");
        }
		mapTotalLength = map.length();
        levelEnded = false;
    }
}
void updatePlayer(){
    //Draw Map and Player
    map = map.replace(playerPos, 1, "@");
    std::cout << map;
	std::cout << talkText;
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
		nextTrigger.insert(end(nextTrigger), jl.jsonGetStringData("firstTrigger"));
		playerPos = jl.jsonGetIntData("playerStartPos");
		const char * c = jl.jsonGetStringData("programTitle").c_str();
		jl.unloadJSON();

		//Sets the title
		SetConsoleTitleA(c);
		while(running) {
			//Checks if the game is in the title or game state
			switch(state){
				case title:
					system("cls");
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
					if(debugMode){
						std::string debugText = "Action Key Pressed: " + BoolToString(p.actionPressed) + "    Player Position: " + std::to_string(playerPos);
						SetConsoleTitleA(debugText.c_str());
					}
					//Check if the player is at the end of the level
					for(int i = 0; i < levelEnd.size(); i++){
						if(levelEnded == false && playerPos == levelEnd[i]) {
							system("cls");
							playerExit = i;
							p.setOnTopChar(".");
							nextMap = jl.jsonGetArrayString("nextMap");
							nextTrigger = jl.jsonGetArrayString("nextTrigger");
							playerStartNextMap = jl.jsonGetArrayInt("playerStartNextMap");
							playerPos = playerStartNextMap[i];
							levelEnded = true;
							jl.unloadJSON();
							map = "";
						}
						if(triggerType[i] == "talk" && talking == false) {
							if(playerPos == triggerTalkPosition[i] && p.actionPressed == true){
								talkText.append(textTrigger[i]);
								talking = true;
							}
						}
						if(triggerType[i] == "change") {
							if(playerPos == triggerChangePosition[i] && p.actionPressed == true){
								map = map.replace(triggerChangeAt[i], 1, triggerChangeTo[i]);
							}
						}
					}
					
					loadNextLevel();
					ClearScreen();
					updatePlayer();
					if(p.actionPressed == false && talking == true){
						talking = false;
						talkText = "";
						system("cls");
					}
					break;
			}
			
		}
	} else {
		SetConsoleTitleA("Error");
		std::cout << "Data Folder not found! Press any key to exit.";
		_getch();
	}
    
}
