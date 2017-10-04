//============================================================================
// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

void program2();
void passbyval(int *x);
int main() {
	int betty=13;
	int sandy=13;
	passbyval(&sandy);
	cout<<"Sandy is: "<<sandy<<endl;
	//program2();
}

void program2(){
	int length=0;
	double *dArray;
	dArray = new double[length];
	string input;
	double finput=0;
	double total=0;
	double average=0;
	cout<<"Enter doubles or enter \"-1\" to stop: "<<endl;
	while(finput!=-1){
		cin>>finput;
		if(finput!=-1){
			//finput = strtof(input.c_str(),0);
			dArray[length]=finput;
			cout<<dArray[length];
			length++;
			total+=dArray[length];}

	}
	cout<<"Total: "<<total;
	cout<<"Exited Loop";
	average=total/length;
	cout<<"Average: "<<average;
}

void passbyval(int *x){
	cout<<"How old is Sandy? ";
	cin>>*x;
}
