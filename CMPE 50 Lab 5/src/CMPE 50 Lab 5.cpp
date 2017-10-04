//============================================================================
// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;


class studentRecord{ //For exercise 1
private:
	double quiz1, quiz2, midterm, final, average;
public:
	studentRecord();

	void set_quiz1(double q1);
	double get_quiz1();

	void set_quiz2(double q2);
	double get_quiz2();

	void set_midterm(double mid);
	double get_midterm();

	void set_final(double final);
	double get_final();

	void set_average(double average);
	double get_average();
	void calc_average();

	void output(ostream& out);

};

class counterType{ //For exercise 2
private:
	int count;
public:
	counterType();
	counterType(int c);

	void increase();
	void decrease();
	int getCount();
	void outputCount(ostream &out);
};

void exercise1();
void exercise2();
//Main////////////////////////////////////////////////////////////////////
int main() {
	exercise1();
	exercise2();
	return 0;
}

studentRecord::studentRecord(){
	quiz1=0;
	quiz2=0;
	midterm=0;
	final=0;
	average=0;
}

void studentRecord::set_quiz1(double q1){
	quiz1 = q1;
}
double studentRecord::get_quiz1(){
	return quiz1;
}
void studentRecord::set_quiz2(double q2){
	quiz2 = q2;
}
double studentRecord::get_quiz2(){
	return quiz2;
}
void studentRecord::set_midterm(double mid){
	midterm=mid;
}
double studentRecord::get_midterm(){
	return midterm;
}
void studentRecord::set_final(double f){
	final = f;
}
double studentRecord::get_final(){
	return final;
}
void studentRecord::set_average(double a){
	average = a;
}
void studentRecord::calc_average(){
	average=(quiz1+quiz2)/10*100/2*0.25+midterm*0.25+final*0.5;
}
double studentRecord::get_average(){
	return average;
}
void studentRecord::output(ostream& out){
	out.setf(ios::fixed);
	out.setf(ios::showpoint);
	out.precision(2);

	out<<"\tQuiz 1: "<<quiz1<<endl;
	out<<"\tQuiz 2: "<<quiz2<<endl;
	out<<"\tMidterm: "<<midterm<<endl;
	out<<"\tFinal exam: "<<final<<endl;
	out<<"\tAverage score: "<<average<<endl;
}

counterType::counterType(){
	count=0;
}
counterType::counterType(int c){
	if(c<0){
		cout<<"You entered a negative number so the count is initialized to 0."<<endl;
		count=0;}
	else{
		count=c;}
}
void counterType::increase(){
	count++;
}
void counterType::decrease(){
	if(count==0){
		cout<<"Count cannot be decreased any more without becoming negative."<<endl;}
	else{
	count--;}
}
int counterType::getCount(){
	return count;
}
void counterType::outputCount(ostream &out){
	out<<count<<endl;
}
void exercise1(){
	studentRecord record;
	double input=0;
	cout<<"Your record was initialized using the default constructor..."<<endl;
	record.output(cout);
	cout<<"Input quiz 1 score (0-10): "<<endl;
	cin>>input;
	record.set_quiz1(input);
	cout<<"Input quiz 2 score(0-10): "<<endl;
	cin>>input;
	record.set_quiz2(input);
	cout<<"Input midterm score (0-100): "<<endl;
	cin>>input;
	record.set_midterm(input);
	cout<<"Input final score(0-100): "<<endl;
	cin>>input;
	record.set_final(input);
	cout<<"Your record after input is: "<<endl;
	record.calc_average();
	record.output(cout);

}
void exercise2(){
	int input=0;
	cout<<"Welcome to exercise 2.\nThis exercise involves implementing a counter class."
		<<"\nCounter 1 was initialized to 0. Input any positive number to initialize counter 2 to: "<<endl;
	cin>>input;
	counterType counter1;
	counterType counter2(input);


	cout<<"Counter 2 increased by 2."<<endl;
	counter2.increase();
	counter2.increase();

	cout<<"Counter 1 attempted to be decreased to a negative value."<<endl;
	counter1.decrease();

	cout<<"Counter 1: "<<counter1.getCount()<<endl; //Using get function
	cout<<"Counter 2: "<<counter2.getCount()<<endl;

	cout<<"\nCounter 2 decreased by 1"<<endl;
	counter2.decrease();
	cout<<"Counter 1: "; counter1.outputCount(cout); //Using output stream function
	cout<<"Counter 2: "; counter2.outputCount(cout);
}

//Output
/*
Your record was initialized using the default constructor...
	Quiz 1: 0.00
	Quiz 2: 0.00
	Midterm: 0.00
	Final exam: 0.00
	Average score: 0.00
Input quiz 1 score (0-10):
8
Input quiz 2 score(0-10):
10
Input midterm score (0-100):
78
Input final score(0-100):
89
Your record after input is:
	Quiz 1: 8.00
	Quiz 2: 10.00
	Midterm: 78.00
	Final exam: 89.00
	Average score: 86.50
Welcome to exercise 2.
This exercise involves implementing a counter class.
Counter 1 was initialized to 0. Input any positive number to initialize counter 2 to:
76
Counter 2 increased by 2.
Counter 1 attempted to be decreased to a negative value.
Count cannot be decreased any more without becoming negative.
Counter 1: 0
Counter 2: 78

Counter 2 decreased by 1
Counter 1: 0
Counter 2: 77
*/
 */
