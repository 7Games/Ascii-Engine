/* Input.cpp ¬ GamerTime ¬ 7Games
	Created: 09/03/20
	Last Edited: 09/03/20
*/
#include <conio.h>
#include "Input.hpp"

char getKeyPress() {
	char key = 127;
	key = _getch();
	return key;
}