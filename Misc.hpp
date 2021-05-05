/* Misc.hpp ¬ ASCIIEngine ¬ 7Games
	Created: 13/03/21
	Last Edited: 24/04/21
*/
#ifndef MISC_H
#define MISC_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <algorithm>
#include <conio.h>
#include <algorithm>
#include <vector>
#include "Player.hpp"
#include "Input.hpp"
#include "JSONLoader.hpp"

std::string BoolToString(bool b) {
  std::string t;
  if(b){
	  t="true";
  } else {
	  t="false";
  }
  return t;
}

#endif //MISC_H