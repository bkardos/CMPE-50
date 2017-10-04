//============================================================================
// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
using namespace std;

//Exercise 1//////////////////////////////////////////////
class Resource{
public:
	Resource();
	Resource(int temp);

	int getStatus() const;
	int getWriteTo() const;
	void setWriteTo(int w);
	void setStatus(int s);
	void output(ostream &out_stream);
	friend bool check_status(Resource &res1, Resource &res2);

private:
	int status;
	int writeTo;
};

Resource::Resource(){
	status=0;
	writeTo=0;}

Resource::Resource(int temp){
	writeTo=temp;
	status=0;}

int Resource::getStatus() const{
	return status;}

int Resource::getWriteTo() const{
	return status;}

void Resource::setStatus(int s){
	status=s;;}

void Resource::setWriteTo(int w){
	writeTo=w;}

void Resource::output(ostream &out_stream){
	out_stream<<"Status: "<<status<<endl;
	out_stream<<"Write To: "<<writeTo<<endl;}

bool check_status(Resource &res1, Resource &res2){
	if (res1.status==1&&res2.status==1){
		cout<<"Resource is available!"<<endl;
		return true;}
	else{
		cout<<"Resource unavailable :("<<endl;
		return false;}
}

//Exercise 2//////////////////////////////////////////////////////////////////////////////////////

class Rational{
private:
	int num;
	int denom;
public:
	Rational();
	Rational(int n, int d);

	void input(istream& in);
	void output(ostream &out);

	friend Rational add(Rational &r1, Rational &r2);
	friend Rational subtract(Rational &r1, Rational &r2);
	friend Rational multiply(Rational &r1, Rational &r2);
	friend Rational division(Rational &r1, Rational &r2);
	friend bool equal(const Rational &r1, const Rational &r2);
	friend bool less_than(const Rational &r1, const Rational &r2);
	void simplify();
	int gcd(int n1, int n2);
};

Rational::Rational(){
	num=0;
	denom=0;}

Rational::Rational(int n, int d){
	if(d==0){
		cout<<"Denominator cannot be 0! Set to 1."<<endl;
		denom=1;}
	else{
		num=n;
		denom=d;}
}

void Rational::input(istream& in){
	int n,d;
	char dump;
	cout<<"Input the numerator and denominator separated by a space: ";
	in>>n>>dump>>d;
	num=n;
	if(d==0){
		cout<<"Denominator cannot be 0! Set to 1."<<endl;
		denom=1;}
	else{
		denom=d;}
}

void Rational::output(ostream &out){
	out<<"Rational number: "<<num<<"/"<<denom<<endl;}

int Rational::gcd(int n1, int n2){
	int temp;
	while (n2!=0){
		temp = n1;
		n1 = n2;
		n2 = temp % n2;}
	return abs(n1);
}
void Rational::simplify(){
	if (num==0){
		return;}
	int g = gcd(num, denom);
	num = num/g;
	denom = denom/g;

	if (num<0&&denom<0){
		num=abs(num);
		denom=abs(denom);}
	else if(denom<0){
		num=-num;
		denom=abs(denom);
	}
}

Rational add(Rational &r1, Rational &r2){
	Rational sum;
	int n,d;
	n=r1.num*r2.denom+r2.num*r1.denom;
	d=r1.denom*r2.denom;
	sum.num=n;
	sum.denom=d;
	sum.simplify();
	return sum;
}

Rational subtract(Rational &r1, Rational &r2){
	Rational sum;
	int n,d;
	n=r1.num*r2.denom-r2.num*r1.denom;
	d=r1.denom*r2.denom;
	sum.num=n;
	sum.denom=d;
	//sum.output(cout);
	sum.simplify();
	return sum;
}

Rational multiply(Rational &r1, Rational &r2){
	Rational prod;
	int n,d;
	n=r1.num*r2.num;
	d=r1.denom*r2.denom;
	prod.num=n;
	prod.denom=d;
	prod.simplify();
	return prod;
}

Rational division(Rational &r1, Rational &r2){
	Rational quot;
	int n,d;
	if (r2.num == 0){
		cout << "Denominator can'tbe 0!"<<endl;
		exit(1);}
	n=r1.num*r2.denom;
	d=r1.denom*r2.num;
	quot.num=n;
	quot.denom=d;
	quot.simplify();
	return quot;
}

bool equal(const Rational &r1, const Rational &r2){
	if (r1.num*r2.denom==r2.num*r1.denom){
		cout<<"The rational numbers are equal!"<<endl;
		return true;}
	else{
		cout<<"The rational numbers aren't equal :("<<endl;
		return false;}
}

bool less_than(const Rational &r1, const Rational &r2){
	if (r1.num*r2.denom<r2.num*r1.denom){
		cout<<"The first number is less than the second."<<endl;
		return true;}
	else{
		cout<<"The first number is greater than the second"<<endl;
		return false;}
}
//MAIN//////////////////////////////////////////////////////////
void exercise1();
void exercise2();
int main() {
	exercise1();
	exercise2();

	return 0;
}

void exercise1(){
	Resource one;
	Resource two(0);
	cout<<"Resource 1:\n"<<endl;
	one.output(cout);
	cout<<endl;
	cout<<"Resource 2:\n"<<endl;
	two.output(cout);
	one.setStatus(1);
	two.setStatus(1);
	cout<<"Checking status..."<<endl;
	check_status(one,two);
}

void exercise2(){
	Rational one(50,-100);
	Rational two;

	cout<<"Please input a rational number in the format (numerator/denominator). Ie: -1/2, 15/32, -300/-401"<<endl;
	two.input(cin);
	cout<<"Adding constructed rational number with your input..."<<endl;
	add(one,two).output(cout);
	cout<<"Subtracting constructed rational number from your input..."<<endl;
	subtract(one,two).output(cout);
	cout<<"Multiplying constructed rational with your input..."<<endl;
	multiply(one,two).output(cout);
	cout<<"Dividing constructed rational with your input..."<<endl;
	division(one,two).output(cout);
	cout<<"Checking if you number is less than the constructed rational number"<<endl;
	less_than(one,two);
}

//Code Output//////////////////////////////////////
/*
Resource 1:

Status: 0
Write To: 0

Resource 2:

Status: 0
Write To: 0
Checking status...
Resource is available!
Please input a rational number in the format (numerator/denominator). Ie: -1/2, 15/32, -300/-401
Input the numerator and denominator separated by a space: 22/-156
Adding constructed rational number with your input...
Rational number: -25/39
Subtracting constructed rational number from your input...
Rational number: -14/39
Multiplying constructed rational with your input...
Rational number: 11/156
Dividing constructed rational with your input...
Rational number: 39/11
Checking if you number is less than the constructed rational number
The first number is less than the second.
*/
