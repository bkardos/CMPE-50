//============================================================================
// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class CDAccount{
private:
	double balance;
	double interest_rate;
	int term; //months until maturity
public:
	double get_balance();
	double get_final();
	double get_rate();
	int get_term();

	double setbalance();
	double set_rate();
	int set_term();

	CDAccount();
};

void exercise1();
void exercise1();
int main() {
	exercise1();
	exercise3();
}

void exercise1(){
	CDAccount myAccount;
	cout<<"Declared a CD Account. Setting values to defaults."<<endl;
	cout<<"Your balance after a term of "<<myAccount.get_term()<<" months is: "<<myAccount.get_final()<<endl;
}

void exercise3(){
	//See Lab 5
}
CDAccount::CDAccount(): balance(100), interest_rate(0.1),term(12){}

double CDAccount::get_balance(){
	return balance;}
double CDAccount::get_final(){
	//cout<<"Calculating balance after maturity..."<<endl;
	double interest = 0;
	interest=balance*interest_rate*term;
	balance+=interest;
	return balance;}
double CDAccount::get_rate(){
	return interest_rate;}
int CDAccount::get_term(){
	return term;}

