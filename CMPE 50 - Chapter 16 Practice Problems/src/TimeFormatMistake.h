/*
 * TimeFormatMistake.h
 *
 *  Created on: May 24, 2017
 *      Author: Lt_Ballzacki
 */

#ifndef TIMEFORMATMISTAKE_H_
#define TIMEFORMATMISTAKE_H_
using namespace std;
#include <iostream>
#include <string>


class TimeFormatMistake {
public:
	TimeFormatMistake();
	TimeFormatMistake(string str);
	string get_exception();
private:
	string message;
};


#endif /* TIMEFORMATMISTAKE_H_ */
