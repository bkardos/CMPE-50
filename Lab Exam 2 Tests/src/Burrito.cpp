/*
 * Burrito.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: Lt_Ballzacki
 */

#include "Burrito.h"
#include <iostream>
#include <string>
using namespace std;

Burrito::Burrito() {
	cout<<"I like burritos!"<<endl;
}

void Burrito::get_toppings(){
	string temp;
	int pos1=0;
	int pos2=0;
	cout<<"Please input 3 toppings here separated by a space: "<<endl;
	getline(cin,temp);
	pos1=temp.find(" ");
	cout<<pos1<<endl;
	topping1=temp.substr(0,pos1);
	pos2=temp.find(" ",pos1+1);
	cout<<pos2<<endl;
	topping2=temp.substr(pos1,pos2);
	cout<<"Your burrito will have "<<topping1<<" and "<<topping2<<" on it!"<<endl;
}
