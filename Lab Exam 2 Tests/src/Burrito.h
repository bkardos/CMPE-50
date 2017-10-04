/*
 * Burrito.h
 *
 *  Created on: Mar 23, 2017
 *      Author: Lt_Ballzacki
 */

#ifndef BURRITO_H
#define BURRITO_H
#include <string>
//using namespace std;

class Burrito {
	public:
		Burrito();
		void get_toppings();

		std::string topping1;
		std::string topping2;
		std::string topping3;

};

#endif /* BURRITO_H*/
