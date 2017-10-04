//============================================================================
// Name        : Lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "burrito.h"
using namespace std;

int main() {
	Burrito myBurrito;
	myBurrito.get_toppings();
}
void project4(){
	char full_name[20]={};
	char first_name[20]={};
	char middle_name[20]={};
	char middle_initial={};
	char last_name={};
	int space1=0;
	int space2=0;
	bool no_middle=false;
	int i=0;
	int j=0;
	int spaces=0;
	cout<<"Please input your first middle and last name: "<<endl;
	cin.getline(full_name,60);

	for(unsigned int i=0;i<strlen(full_name);i++){
		if(isspace(full_name[i])){
			spaces++;}
	if(spaces>1){
		no_middle=true;}
	if(no_middle){
		while(!isspace(full_name[i])){
			first_name[i]=full_name[i];
			i++;}
			i+=1; //Skips space
	}
}
