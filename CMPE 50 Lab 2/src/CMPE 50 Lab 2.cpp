//============================================================================
// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

double Add(double a, double b);
int Add(int a, int b);
void Add(char a[], char b[]);

void ArySwap();

void studentReport();
double best(double ary[2][5], int row);
double worst(double ary[2][5], int row);
double average(double ary[2][5],int row);
void print_char(char ch, int num);
int main() {

//Excercise 1//////////////////////////////////////////////////////////
/*
	char selector;
	int a1;
	int b1;
	double a2;
	double b2;
	char a3[100];
	char b3[100];
	cout<<"Would you like to add 2 integers 2 decimals or 2 words?/nEnter i, d, or c: "<<endl;
	cin>>selector;
	if (selector=='i'){
		cout<<"Enter your two integers: "<<endl;
		cin>>a1>>b1;
		cout<<Add(a1,b1)<<endl;}
	if (selector=='d'){
		cout<<"Enter your two decimal numbers: "<<endl;
		cin>>a2>>b2;
		cout<<Add(a2,b2);}
	if (selector=='c'){
		cout<<"Enter your first word: "<<endl;
		cin >>a3;
		cout<<"Enter your second word: "<<endl;
		cin>>b3;
		Add(a3,b3);}
*/
//Excercise 2////////////////////////////////////////////////////////
	//ArySwap();
//Excercise 3///////////////////////////////////////////////////////
studentReport();
	return 0;
}


//Functions
double Add(double a, double b){
	return a+b;
}
int Add(int a, int b){
	return a+b;
}

void Add(char a[], char b[]){
	cout<<a<<b<<endl;
}

void ArySwap(){
	char ary[11];
	char ch;
	int size = 0;
	cout<<"Hello, you ran a function to return the reverse order of 10 letters or less."<<endl;
	while (ch!='.'){
		if (size<=10){
		cout<<"Please input letter "<<size+1<<" or \'.\' to end word: "<<endl;
		cin>>ch;
			if (ch!='.'){
			ary[size]=ch;
			size++;}
		}
		else{
			cout<<"You entered more than 10 letters. Please try again."<<endl;
			size = 0;
		}
	}
	for (int i=size-1; i >= 0; i--){
		cout<<ary[i];
	}
}

void studentReport(){
	double val[2][5];
	double best_hw=0;
	double best_lab=0;
	double worst_hw=0;
	double worst_lab=0;
	double avg_hw=0;
	double avg_lab=0;
	cout <<"Please enter five HW scores [0 – 100]: "<<endl;
	for (int i=0;i<5;i++){
		cout<<"Input HW Score"<<i+1<<": "<<endl;
		cin>>val[0][i];
	}
	cout <<"Now enter five lab scores [0 – 100]: "<<endl;
	for (int i=0;i<5;i++){
		cout<<"Input lab Score"<<i+1<<": "<<endl;
		cin>>val[1][i];
	}

	//27

	cout<<"       1\t2\t3\t4\t5\n       ";
	print_char('*',33);//Line Length is 40
	best_hw=best(val,0);
	best_lab=best(val,1);
	cout<<"Best hw: "<<best_hw<<endl;
	cout<<"Best lab: "<<best_lab<<endl;
	worst_hw=worst(val,0);
	worst_lab=worst(val,1);
	cout<<"Worst hw: "<<worst_hw<<endl;
	cout<<"Worst lab: "<<worst_lab<<endl;
	avg_hw=average(val,0);
	avg_lab=average(val,1);
	cout<<"Avg hw: "<<avg_hw<<endl;
	cout<<"Avg lab: "<<avg_lab<<endl;
}

double best(double ary[2][5], int row){
	double best = 0;
	for (int i = 0; i <5; i++){
		if (ary[row][i] > best){
			best = ary[row][i];}
	}
	return best;
}

double worst(double ary[2][5], int row){
	double worst;
	for (int i = 0; i <5; i++){
		if (ary[row][i] < worst){
			worst = ary[row][i];}
	}
	return worst;
}

double average(double ary[2][5],int row){
	double avg=0;
	double sum=0;
	for (int i = 0; i <5; i++){
		sum+=ary[row][i];
	}
	avg=sum/5;
	return avg;
}

void total_average(double ary[2][5]){
	for (int i = 0; i <5; i++){
		double sum=0;
		sum=ary[0][i]+ary[1][i];
		ary[3][i]=sum;}
}

void print_char(char ch, int num){
	for (int i=0; i<=num; i++){
		cout<<ch;
	}
}

////////////////////////////////////////////////////////////////////
/*Excercise 1 Output:
Would you like to add 2 integers 2 decimals or 2 words?/nEnter i, d, or c:
i
Enter your two integers:
45
87
132

Would you like to add 2 integers 2 decimals or 2 words?/nEnter i, d, or c:
d
Enter your two decimal numbers:
3.56
67.34
70.9

Would you like to add 2 integers 2 decimals or 2 words?/nEnter i, d, or c:
c
Enter your first word:
bar
Enter your second word:
tender
bartender
 */
//////////////////////////////////////////////////////////
/*Excercise 2 Output:

Hello, you ran a function to return the reverse order of 10 letters or less.
Please input letter 1 or '.' to end word:
a
Please input letter 2 or '.' to end word:
b
Please input letter 3 or '.' to end word:
c
Please input letter 4 or '.' to end word:
d
Please input letter 5 or '.' to end word:
f
Please input letter 6 or '.' to end word:
f
Please input letter 7 or '.' to end word:
f
Please input letter 8 or '.' to end word:
f
fPlease input letter 9 or '.' to end word:

Please input letter 10 or '.' to end word:
f
Please input letter 11 or '.' to end word:
f
You entered more than 10 letters. Please try again.
Please input letter 1 or '.' to end word:
a
Please input letter 2 or '.' to end word:
b
Please input letter 3 or '.' to end word:
c
Please input letter 4 or '.' to end word:
.
cba
 */
