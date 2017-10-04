//============================================================================
// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>
#include "StringVar.h"
#include "Pairs.h"
using namespace std;

class Money{
	public:
	Money();
	friend Money operator +(const Money& amount1, const Money& amount2);
	friend Money operator -(const Money& amount1, const Money& amount2);
	friend Money operator -(const Money& amount);
	friend bool operator <(const Money& amount1, const Money& amount2);
	friend bool operator <=(const Money& amount1, const Money& amount2);
	friend bool operator >(const Money& amount1, const Money& amount2);
	friend bool operator >=(const Money& amount1, const Money& amount2);
	friend ostream &operator<<(ostream &out, Money total);



	void get_value();
	void get_values();
	void set_values();
	void set_value(int val);
	Money percent(int percent_figure) const;
	string format(int total);
	private:
		long all_cents;
		//long dollars;
		//long cents;
		long *amounts;
		int count;

};

void exercise1();
void exercise2();
void project4();
void moneytst();
int main() { //MAIN////////////////////////////////////////////////////////////////////////////////////////
	//exercise1();
	//exercise2();
	//project4();
	moneytst();
}

//void exercise1(){
//	Money dolla;
//	Money dolla1;
//	Money total;
//	//Money purse;
//
//	dolla.set_value(60);
//	dolla1.set_value(40);
//
//	total = -(dolla + dolla1);
//
//	cout.setf(ios::fixed);
//	cout.setf(ios::showpoint);
//	cout.precision(2);
//	cout<<total.get_value()<<endl;
//	if (dolla<dolla1){
//		cout<<"Dolla is less than dolla1."<<endl;}
//	else{
//		cout<<"Dolla isn't less."<<endl;
//	}
//	dolla.percent(10);
//	cout<<dolla.get_value();
//}

void exercise2(){
	Pairs x;
	Pairs y(2);
	Pairs z(4,5);
	cout<<"Input data for x: "<<endl;
	cin>>x;
	cout<<x.get_first()<<endl;
	cout<<x.get_second()<<endl;
	cout<<y.get_first()<<endl;
	cout<<y.get_second()<<endl;
	cout<<z.get_first()<<endl;
	cout<<z.get_second()<<endl;
	cout<<x<<endl;
	cout<<y<<endl;
	cout<<z<<endl;
	x=y+z;
	cout<<x<<endl;
	x=3*x;
	cout<<x<<endl;
}

void moneytst(){
	Money zack;
	zack.set_values();
	zack.get_values();
	cout<<"Your account sum is: "<<zack<<endl;

}




void project4(){
	StringVar str;
	str.copy_piece();
}

Money::Money(){
	all_cents=0;
	count=0;
	amounts=new long[count];
}
void Money::set_value(int val){
	all_cents=val;}
void Money::get_value(){
	int dollar=0;
	int cents=0;
	dollar=all_cents/100;
	cents=all_cents%100;
	cout<<"The value is: $"<<dollar<<"."<<cents<<endl;}

Money Money::percent(int percent_figure) const{
	Money percent;
	percent.all_cents=percent_figure*0.01;
	return percent;
}
Money operator +(const Money& amount1, const Money& amount2){
	Money temp;
	temp.all_cents=amount1.all_cents+amount2.all_cents;
	return temp;}
Money operator -(const Money& amount1, const Money& amount2){
	Money temp;
	temp.all_cents=amount1.all_cents+amount2.all_cents;
	return temp;}
Money operator -(const Money& amount){
	Money temp;
	temp.all_cents=-amount.all_cents;
	return temp;}
ostream &operator <<(ostream &out, Money total){
	out<<"$"<<total.all_cents/100<<"."<<total.all_cents%100;
	return out;
}
bool operator <(const Money& amount1, const Money& amount2){
	return (amount1.all_cents<amount2.all_cents);}
bool operator <=(const Money& amount1, const Money& amount2){
	return (amount1.all_cents<=amount2.all_cents);}
bool operator >(const Money& amount1, const Money& amount2){
	return (amount1.all_cents>amount2.all_cents);}
bool operator >=(const Money& amount1, const Money& amount2){
	return (amount1.all_cents>=amount2.all_cents);}

void Money::set_values(){

	string input="";
	string temp;
	int dot=0;
	int dollars=0;
	int cents=0;
	cout<<"Please enter a money value in the format $10.49, or enter \"e\" to exit: "<<endl;
	while(input!="e"){
		getline(cin,input);
		if(input[0]=='$'){
			dot=input.find(".",0);
			temp=input.substr(1,dot-1);
			dollars=(atoi(temp.c_str()));
			cout<<"Dollars: "<<temp<<endl;
			temp=input.substr(dot+1);
			cents=(atoi(temp.c_str()));
			cout<<"Cents: "<<temp<<endl;
			amounts[count]=dollars*100+cents;
			all_cents+=amounts[count];
			count++;
		}
	}
	cout<<"All cents: "<<all_cents<<endl;

}
void Money::get_values(){
	int dollar=0;
	int cents=0;
	cout<<"The values you entered are: ";
	for (int i=0;i<count; i++){
		dollar=amounts[i]/100;
		cents=amounts[i]%100;
		cout<<"$"<<dollar<<"."<<cents<<", ";}

}

//string format(int total){
//	string out;
//	int dollar=total/100;
//	string dollar=
//	int cents=total%100;
//	out="$"+to_string(dollar)+"."+to_string(cents);
//	return out;
//}
