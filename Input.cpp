/* Input.cpp ¬ ASCIIEngine ¬ 7Games
	Created: 09/03/20
	Last Edited: 31/03/20
*/
#include <conio.h>
#include "Input.hpp"

char ASCIIEngine::Input::getKeyPress() {
	char key = 127;
	key = _getch();
	return key;
}