//============================================================================
// Name        : Zack Nicholson
// Professor   : Tarng
// Class       : CMPE 50 - Section 1
// Date        : May 11, 2017
//============================================================================

#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "figure.h"

class circle:public figure{
public:
	virtual void erase();
	virtual void draw();
};

#endif /* CIRCLE_H_ */
