/*
 * StringVar.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: Lt_Ballzacki
 */

#include "StringVar.h"
#include <string>
#include <iostream>
using namespace std;

StringVar::StringVar(){
	value = new char[max_length + 1];//+1 is for '\0'.
	value[0] = '\0';
	max_length=100;
	cout<<"StringVar initialized..."<<endl;}

string StringVar::copy_piece(){
	return "Hello Cunt";}
