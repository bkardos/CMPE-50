//============================================================================
// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdlib.h>
using namespace std;

class seatManager{
	public:
		seatManager(int r);
		~seatManager();
		void display(ostream &out);
		void fillSeats();
		void assignSeat(string st);
		bool checkSeat(string st);
		bool checkFull();
		int char_to_row(char d);
		int char_to_column(char d);
		void getRows();
	private:
		int rows;
		char **seats;
};

seatManager::seatManager(int r){
	rows=r;
	seats = new char*[rows];
	for (int i=0;i<rows;i++){
		seats[i] = new char[4];
		seats[i][0] = 'A';
		seats[i][1] = 'B';
		seats[i][2] = 'C';
		seats[i][3] = 'D';
	}
}
seatManager::~seatManager(){
	for(int i=0;i<rows;i++){
		delete[] seats[i];}
	delete[] seats;
}

bool seatManager::checkSeat(string st){
	//Returns true if seat is available or properly inputted.
	int row = char_to_row(st[0]);
	int column = char_to_column(st[1]);
	if(seats[row-1][column]=='X'){
		cout<<"Seat already taken."<<endl;
		return false;
	}
	else{
		return true;}
}

bool seatManager::checkFull(){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < 4; j++){
			if (seats[i][j] != 'X'){
				return false;}
		}
	}
	return true;
}
int seatManager::char_to_row(char d){
	return d - '0';
}
int seatManager::char_to_column(char d){
	if (d<='z'&&d>='a'){
		return d - 'a';}
	else{return d - 'A';}
}

void seatManager::assignSeat(string st){
	int row = char_to_row(st[0]);
	int column = char_to_column(st[1]);
	seats[row - 1][column] = 'X';
}

void seatManager::fillSeats(){
		string seat;
		while (seat[0] !='e'){
			cout<<"Enter a seat in the format (1A, 2B, 4C, 8D) or type \"end\" to end:"<<endl;
			cin>>seat;
			if(seat[0]!='e'){
				checkSeat(seat);
				assignSeat(seat);
			}
			if(checkFull()){
				cout<<"No more seats available."<<endl;
				exit(1);}
		}
	cout<<"Finished booking seats!"<<endl;
}

void seatManager::display(ostream &out){
	for(int i=0; i<rows;i++){
		out<<i+1<<" "<<seats[i][0]<<" "<<seats[i][1]<<" "<<seats[i][2]<<" "<<seats[i][3]<<endl;
	}
}

void seatManager::getRows(){
	cout<<"Rows: "<<rows<<endl;
}
void exercise1(){
	cout<<"Welcome to the airplane seat manager program..."<<endl;

	char selector;
	cout<<"Would you like to read the seats in from a test file or the console? Enter \"c\" for console or \"f\" for file"<<endl;
	cin>>selector;

	if (selector=='c'){
		int size;
		cout<<"Please enter the number of rows on your airplane: "<<endl;
		cin>>size;
		seatManager config(size);
		cout<<"Created your airplane! Showing empty seat configuration."<<endl;
		config.display(cout);
		config.fillSeats();
		config.display(cout);
	}
	else{
		ifstream fin;
		fin.open("seats.txt");
		if (fin.fail()){
			cout<<"File failed to open"<<endl;
			exit(1);}
		else{cout<<"File opened successfully!"<<endl;}

		int rowSize;
		string seat;

		fin >> rowSize;
		fin.get(); // ignore the new line character.
		seatManager config(rowSize);
		config.getRows();
		while (seat[0] !='e'){
			fin>>seat;
			if(seat[0]!='e'){
				config.checkSeat(seat);
				config.assignSeat(seat);
			if(config.checkFull()){
				cout<<"No more seats available."<<endl;
				exit(1);}
			}
		}
		config.display(cout);
	}
}

char* delRepeats(const char in[], int size){

	char *noRpt=new char[size+1];
	noRpt[0]=in[0];
	int k=1;
	for (int i = 1; i < size; i++) {
		bool exist = false;
		for (int j = 0; j < i; j++) {
			if (in[j] == in[i]) {
				exist = true;
				break;}
		}
		if(!exist){
			noRpt[k] = in[i];
			k++;}
	}
	noRpt[k]='\0';
	return noRpt;
}
int main(){
	//exercise1();
	char str[100]="to be or not to be";
	cout<<delRepeats(str,strlen(str))<<endl;
}

//Program Output
/*
Run 1:

Welcome to the airplane seat manager program...
Would you like to read the seats in from a test file or the console? Enter "c" for console or "f" for file
c
Please enter the number of rows on your airplane:
9
Created your airplane! Showing empty seat configuration.
1 A B C D
2 A B C D
3 A B C D
4 A B C D
5 A B C D
6 A B C D
7 A B C D
8 A B C D
9 A B C D
Enter a seat in the format (1A, 2B, 4C, 8D) or type "end" to end:
1A
Enter a seat in the format (1A, 2B, 4C, 8D) or type "end" to end:
2B
Enter a seat in the format (1A, 2B, 4C, 8D) or type "end" to end:
3C
Enter a seat in the format (1A, 2B, 4C, 8D) or type "end" to end:
4D
Enter a seat in the format (1A, 2B, 4C, 8D) or type "end" to end:
1A
Seat already taken.
Enter a seat in the format (1A, 2B, 4C, 8D) or type "end" to end:
1B
Enter a seat in the format (1A, 2B, 4C, 8D) or type "end" to end:
4C
Enter a seat in the format (1A, 2B, 4C, 8D) or type "end" to end:
end
Finished booking seats!
1 X X C D
2 A X C D
3 A B X D
4 A B X X
5 A B C D
6 A B C D
7 A B C D
8 A B C D
9 A B C D


Run 2:

Welcome to the airplane seat manager program...
Would you like to read the seats in from a test file or the console? Enter "c" for console or "f" for file
f
File opened successfully!
Rows: 7
Seat already taken.
1 X B C D
2 X X X X
3 X B C D
4 X B C D
5 X B C D
6 X B C D
7 X B C X
*/
