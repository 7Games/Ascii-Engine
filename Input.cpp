#include <conio.h>
#include "Input.hpp"

char getKeyPress() {
	char key = 127;
	key = _getch();
	return key;
}