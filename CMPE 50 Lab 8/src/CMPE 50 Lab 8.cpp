//============================================================================
// Name        : CMPE.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Polynomial.h"
#include "Complex.h"
using namespace std;

void exercise1();
void exercise2();
int main() {
	cout << "Starting Exercise 1: Polynomials..."<<endl;
	exercise1();
	cout<<"Starting Exercise 2: Complex Numbers..."<<endl;
	exercise2();
	return 0;
}

void exercise1(){
	int c = 2;
	double test_cfa[] = {1.1, 2.2, 3.3};
	double test_cfb[] = {4.4, 5.5};
	Polynomial a(test_cfa, 2);
	Polynomial b(test_cfb, 1);

	cout<<"Polynomial + Polynomial"<<endl;
	cout << a;
	cout << "+" << endl;
	cout << b;
	cout << "=" << endl;
	cout << a+b << endl;
	cout << endl;

	cout<<"Constant + Polynomial"<<endl;
	cout << c << endl;
	cout << "+" << endl;
	cout << a;
	cout << "=" << endl;
	cout << c + a << endl;
	cout << endl;

	cout<<"Polynomial + Constant"<<endl;
	cout << a;
	cout << "+" << endl;
	cout << c << endl;
	cout << "=" << endl;
	cout << a + c << endl;
	cout << endl;

	cout<<"Polynomial - Polynomial"<<endl;
	cout << a;
	cout << "-" << endl;
	cout << b;
	cout << "=" << endl;
	cout << a - b << endl;
	cout << endl;

	cout<<"Constant - Polynomial"<<endl;
	cout << c << endl;
	cout << "-" << endl;
	cout << a;
	cout << "=" << endl;
	cout << c - a << endl;
	cout << endl;

	cout<<"Polynomial - Constant"<<endl;
	cout << a;
	cout << "-" << endl;
	cout << c << endl;
	cout << "=" << endl;
	cout << a - c << endl;
	cout << endl;

	cout<<"Polynomial * Polynomial"<<endl;
	cout << a;
	cout << "*" << endl;
	cout << b;
	cout << "=" << endl;
	cout << a * b << endl;
	cout << endl;

	cout<<"Constant * Polynomial"<<endl;
	cout << c << endl;
	cout << "*" << endl;
	cout << a;
	cout << "=" << endl;
	cout << c * a << endl;
	cout << endl;

	cout<<"Polynomial * Constant"<<endl;
	cout << a;
	cout << "*" << endl;
	cout << c << endl;
	cout << "=" << endl;
	cout << a * c << endl;
	cout << endl;

	cout<<"Evaluating Polynomial at a value."<<endl;
	cout<<"a(2.35) = "<<a.evaluate(2.35)<<endl;
}

void exercise2(){
	Complex com_a, com_b;
	cout<<"Please input a complex number(com_a) like a + b * i:\n";
	cin>>com_a;
	cout<<"You just inputted: ";
	cout<<com_a;

	cout<<"Please input a complex number(com_b) like a + b * i:\n";
	cin>>com_b;
	cout<<"You just inputted: ";
	cout<<com_b;

	cout<<com_a << " + \n" << com_b;
	cout<<com_a + com_b << endl;
	cout<<endl;

	cout<<com_a << " - \n" << com_b;
	cout<<com_a - com_b << endl;
	cout<<endl;

	cout<<com_a << " * \n" << com_b;
	cout<<com_a * com_b <<endl;
	cout<<endl;


	cout<<com_a<<" == \n"<<com_b;
	if(com_a==com_b){
		cout<<"The complex numbers are equal!"<<endl;}
	else{
		cout<<"The numbers are different."<<endl;
	}
	cout<<endl;
}

//Program Output///////////////////////////////////////////////////////////////////
/*
Starting Exercise 1: Polynomials...
Polynomial + Polynomial
3.3*x^2 + 2.2*x^1 + 1.1*x^0
+
5.5*x^1 + 4.4*x^0
=
3.3*x^2 + 7.7*x^1 + 5.5*x^0


Constant + Polynomial
2
+
3.3*x^2 + 2.2*x^1 + 1.1*x^0
=
3.3*x^2 + 2.2*x^1 + 3.1*x^0


Polynomial + Constant
3.3*x^2 + 2.2*x^1 + 1.1*x^0
+
2
=
3.3*x^2 + 2.2*x^1 + 3.1*x^0


Polynomial - Polynomial
3.3*x^2 + 2.2*x^1 + 1.1*x^0
-
5.5*x^1 + 4.4*x^0
=
3.3*x^2 + -3.3*x^1 + -3.3*x^0


Constant - Polynomial
2
-
3.3*x^2 + 2.2*x^1 + 1.1*x^0
=
-3.3*x^2 + -2.2*x^1 + 0.9*x^0


Polynomial - Constant
3.3*x^2 + 2.2*x^1 + 1.1*x^0
-
2
=
3.3*x^2 + 2.2*x^1 + -0.9*x^0


Polynomial * Polynomial
3.3*x^2 + 2.2*x^1 + 1.1*x^0
*
5.5*x^1 + 4.4*x^0
=
18.15*x^3 + 26.62*x^2 + 15.73*x^1 + 4.84*x^0


Constant * Polynomial
2
*
3.3*x^2 + 2.2*x^1 + 1.1*x^0
=
6.6*x^2 + 4.4*x^1 + 2.2*x^0


Polynomial * Constant
3.3*x^2 + 2.2*x^1 + 1.1*x^0
*
2
=
6.6*x^2 + 4.4*x^1 + 2.2*x^0


Evaluating Polynomial at a value.
a(2.35) = 24.4943
Starting Exercise 2: Complex Numbers...
Please input a complex number(com_a) like a + b * i:
4+3*i
You just inputted: 4 + 3 * i
Please input a complex number(com_b) like a + b * i:
3-7*i
You just inputted: 3 - 7 * i
4 + 3 * i
 +
3 - 7 * i
7 - 4 * i


4 + 3 * i
 -
3 - 7 * i
1 + 10 * i


4 + 3 * i
 *
3 - 7 * i
33 - 19 * i


4 + 3 * i
 ==
3 - 7 * i
The numbers are different.
 */
