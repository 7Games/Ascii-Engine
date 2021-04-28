/* Player.hpp ¬ ASCIIEngine ¬ 7Games
	Created: 09/03/21
	Last Edited: 24/04/21
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string.h>
#include "Input.hpp"

namespace ASCIIEngine {
	class Player{
	public:
		bool actionPressed = false;
		int UpdatePos(int playerPos, int mapHorLength, std::string map);
		std::string getOnTopChar();
		void setOnTopChar(std::string c);
	private:
		using input = ASCIIEngine::Input;
		input in;
	};
}

#endif //PLAYER_H