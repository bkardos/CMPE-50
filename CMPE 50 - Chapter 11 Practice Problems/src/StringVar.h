/*
 * StringVar.h
 *
 *  Created on: Mar 23, 2017
 *      Author: Lt_Ballzacki
 */

#ifndef STRINGVAR_H_
#define STRINGVAR_H_
#include <string>
using namespace std;

class StringVar{
public:
	StringVar();
	string copy_piece();
private:
	char *value;
	int max_length;
};

#endif /* STRINGVAR_H_ */
