//============================================================================
// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iomanip>
using namespace std;

void exercise1();
void exercise3();
void project4();
void formatting();
int main() {
	//exercise1();
	//exercise3();
	//project4();
	formatting();
}

void exercise1(){
	char str[]="Zack 18 Ladykiller";
	char name[20]="";
	char c_age[20]={};
	int age=0;
	char title[30]="";
	int i=0;
	int j=0;
	int k=0;

	while(!isspace(str[i])){
		name[i]=str[i];
		i++;}
	i+=1; //Skips space
	while(!isspace(str[i])){
		c_age[j]=str[i];
		i++; j++;}
	age=atoi(c_age);
	i++; //Skip space
	while(str[i]!='\0'){
		title[k]=str[i];
		i++; k++;
	}
	cout<<name<<" "<<age<<" "<<title<<endl;

}

void exercise3(){
	string st1;
	int pos=0;
	char first_initial={0};
	char last_initial={0};
	char loop='y';
	do{
		cout<<"Input your first and last name separated by a space: ";
		getline(cin,st1);
		first_initial=st1[0];
		pos=st1.find(" ");
		last_initial=st1[pos+1];
		cout<<"Your first initial is \""<<first_initial<<"\" and your last initial is \""<<last_initial<<"\"."<<endl;
		cout<<"Would you like to run the exercise again? Input \'y\' to continue: "<<endl;
		cin>>(loop);
		cin.ignore(10,'\n'); //Flushes the null char cin leaves in the stream so getline is not automatically terminated.
	}while(loop=='y');
	cout<<"Program terminated..."<<endl;
}


void project4(){
	string full_name;
	string first_name;
	string middle_name;
	string middle_initial;
	string last_name;
	int space1=0;
	int space2=0;
	//int newline=0;
	bool no_middle=false;
	cout<<"Please input your first middle and last name: "<<endl;
	getline(cin,full_name);
	space1=full_name.find(" ");
	space2=full_name.find(" ",space1+1); //Looks for spaces after the position of the first space
	cout<<"Spaces: "<<space1<<" "<<space2<<endl;
	if (space2<0){
		cout<<"No Middle Name Inputted..."<<endl;
		no_middle = true;}
	first_name=full_name.substr(0,space1);
	if (no_middle){
		first_name=full_name.substr(0,space1);
		last_name=full_name.substr(space1,-1);
		cout<<"Hello: "<<last_name<<", "<<first_name<<endl;}
	else{
		first_name=full_name.substr(0,space1);
		middle_name=full_name.substr(space1+1,space2-space1); //Middle name start after space one and is the length between spaces
		last_name=full_name.substr(space2,-1);
		middle_initial=middle_name[0];
		middle_initial+=".";

		cout<<"Hello: "<<last_name<<", "<<first_name<<" "<<middle_initial<<endl;
	}
}

void formatting(){
	string input;
	int length=0;
	double total=0;
	double *ary=new double[length];
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout<<"Input doubles or \"e\" to stop: "<<endl;
	while(input!="e"){
		cin>>input;
		if (input!="e"){
			ary[length]=atof(input.c_str());
			total+=ary[length];
			cout<<setw(10)<<ary[length]<<endl;
			length++;}
	}
	double average=total/length;
	cout<<"Average: "<<average<<endl;
	delete [] ary;
}
