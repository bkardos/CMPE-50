//============================================================================
// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TimeFormatMistake.h"
#include <string>
#include <cstdlib>
using namespace std;

void time();
int main() {
time();
}

void time(){
	string time ="";
	string temp="";
	int hour=0;
	int minute=0;
	int index=0;
	cout<<"Welcome to time exception function."<<endl;
	cout<<"Please input a time in the following format, 12:30 : ";
	try{
		cin>>time;
		index=time.find(":",0);
		if(index<0){
			throw TimeFormatMistake();}
		temp=time.substr(0,index);
		hour=atoi(temp.c_str());
		temp=time.substr(index+1);
		minute=atoi(temp.c_str());
		if (hour>12){
			throw TimeFormatMistake("Cannot have more than 12 hours!");}
		if(minute>59){
			throw TimeFormatMistake("Cannot have more than 59 minutes!");}
		cout<<"Time is <"<<time<<">"<<endl;
	}
	catch (TimeFormatMistake &obj){
		cout<<obj.get_exception();
	}
}
