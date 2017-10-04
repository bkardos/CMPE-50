//============================================================================
// Name        : Zack Nicholson
// Professor   : Tarng
// Class       : CMPE 50 - Section 1
// Date        : May 11, 2017
//============================================================================

#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include "figure.h"

class triangle:public figure{
public:
	virtual void erase();
	virtual void draw();
};

#endif /* TRIANGLE_H_ */
