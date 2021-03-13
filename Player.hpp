/* Player.hpp ¬ GamerTime ¬ 7Games
	Created: 09/03/20
	Last Edited: 13/03/20
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string.h>

int UpdatePos(int playerPos, int mapHorLength, std::string map);
std::string getOnTopChar();
void setOnTopChar(std::string c);

#endif //PLAYER_H