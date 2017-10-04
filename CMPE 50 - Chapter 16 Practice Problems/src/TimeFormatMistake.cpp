/*
 * TimeFormatMistake.cpp
 *
 *  Created on: May 24, 2017
 *      Author: Lt_Ballzacki
 */

#include "TimeFormatMistake.h"
using namespace std;
#include <iostream>
#include <string>

TimeFormatMistake::TimeFormatMistake() {
	message="Time Format Invalid!";
}
TimeFormatMistake::TimeFormatMistake(string str) {
	message=str;
}
string TimeFormatMistake::get_exception(){
	return message;
}
