//============================================================================
// Name        : Zack Nicholson
// Professor   : Tarng
// Class       : CMPE 50 - Section 1
// Date        : May 11, 2017
//============================================================================

#include "figure.h"
#include <iostream>
using namespace std;

void figure::erase(){
	cout<< "Erasing Figure" << endl;}
void figure::draw(){
	cout << "Drawing Figure." << endl;}
void figure::center(){
	cout<<"Centering Figure..."<<endl;
	erase();
	draw();
}
