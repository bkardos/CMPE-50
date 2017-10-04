//============================================================================
// Name        : Zack Nicholson
// Professor   : Tarng
// Class       : CMPE 50 - Section 1
// Date        : May 11, 2017
//============================================================================

#include <iostream>
#include <fstream>
#include "salariedemployee.h"
#include "figure.h"
#include "circle.h"
#include "triangle.h"
using namespace std;

class Administrator:public SalariedEmployee{
	public:
		void set_supervisor(string n);
		void set_title(string n);
		void set_responsibility(string n);
		void get_data();
		string get_supervisor();
		string get_title();
		string get_responsibility();
		void print(ostream &out);
		void print_check();

	private:
		string title;
		string responsibility;
		string supervisor;
};


void exercise1();
void exercise2();

void myDraw(figure *fig){
	fig->draw();
	cout << "\n myDraw: Derived class object calling center(). \n";
	fig->center();
}
int main() {
	//exercise1();
	exercise2();

}

void exercise1(){
	Administrator admin;

	cout<<"Welcome to exercise 1: Employee Program."<<endl;
	cout<<"Running supervisor data filler function..."<<endl;
	admin.get_data();
	admin.print(cout);
	cout<<endl;
	admin.print_check();
}

void exercise2(){
	cout<<"Welcome to exercise 2: Graphics Program."<<endl;

	figure *fig;
	triangle *tri = new triangle;

	fig = tri;
	fig->draw();
	cout << "\n Derived class Triangle object calling center(). \n";
	fig->center();

	myDraw(tri);

	circle *cir = new circle;
	fig = cir;
	cir->draw();
	cout << "\n Derived class Circle object calling center(). \n";
	cir->center();

	myDraw(cir);
}
void Administrator::set_supervisor(string n){
	supervisor=n;
}

void Administrator::set_title(string n){
	title=n;
}

void Administrator::set_responsibility(string n){
	responsibility=n;
}

void Administrator::get_data(){
	string input = "";
	double din=0;

	cout<<"Input your administrator's name: "; cin>>input;
	set_name(input);
	cout<<"Input your administrator's title: "; cin>>input;
	set_title(input);
	cout<<"Input your administrator's area of responsibility: "; cin>>input;
	set_responsibility(input);
	cout<<"Input your administrator's immediate supervisor: "; cin>>input;
	set_supervisor(input);
	cout<<"Input your administrator's salary: "; cin>>din;
	set_salary(din);
	cout<<"Input your administrator's SSN: "; cin>>input;
	set_ssn(input);
}

string Administrator::get_title(){
	return title;
}
string Administrator::get_responsibility(){
	return responsibility;
}
string Administrator::get_supervisor(){
	return supervisor;
}

void Administrator::print(ostream &out){
	out<<"Title: "<<get_title()<<endl;
	out<<"Name: "<<get_name()<<endl;
	out<<"Salary: $"<< get_salary()<<endl;
	out<<"Area of Responsibility: "<<get_responsibility()<<endl;
	out<<"Supervisor: "<<get_supervisor()<<endl;
}

void Administrator::print_check(){
	set_net_pay(salary);
	cout << "\n__________________________________________________\n";
	cout << "Pay to the order of "<<get_name()<<endl;
	cout <<"The sum of "<<get_net_pay()<<" Dollars\n";
	cout << "_________________________________________________\n";
	cout << "Check Stub NOT NEGOTIABLE \n";
	cout << "Employee Number: "<<get_ssn()<< endl;
	cout << "Salaried Employee. Regular Pay: "<< salary << endl;
	cout << "_________________________________________________\n";
}

//Program Output
/*
===========================Exercise 1======================================
Welcome to exercise 1: Employee Program.
Running supervisor data filler function...
Input your administrator's name: Paul
Input your administrator's title: Director
Input your administrator's area of responsibility: SSD's
Input your administrator's immediate supervisor: Bill
Input your administrator's salary: 40000
Input your administrator's SSN: 567-34-9966
Title: Director
Name: Paul
Salary: $40000
Area of Responsibility: SSD's
Supervisor: Bill


__________________________________________________
Pay to the order of Paul
The sum of 40000 Dollars
_________________________________________________
Check Stub NOT NEGOTIABLE
Employee Number: 567-34-9966
Salaried Employee. Regular Pay: 40000
_________________________________________________

=======================Exercise 2 - Without Virtual========================
Welcome to exercise 2: Graphics Program.
Drawing Figure.

 Derived class Triangle object calling center().
Centering Figure...
Erasing Figure
Drawing Figure.
Drawing Figure.

 myDraw: Derived class object calling center().
Centering Figure...
Erasing Figure
Drawing Figure.
Drawing Circle.

 Derived class Circle object calling center().
Centering Figure...
Erasing Figure
Drawing Figure.
Drawing Figure.

 myDraw: Derived class object calling center().
Centering Figure...
Erasing Figure
Drawing Figure.

========================Exercise 2 - With Virtual==========================
Welcome to exercise 2: Graphics Program.
Drawing Triangle.

 Derived class Triangle object calling center().
Centering Figure...
Erasing Triangle.
Drawing Triangle.
Drawing Triangle.

 myDraw: Derived class object calling center().
Centering Figure...
Erasing Triangle.
Drawing Triangle.
Drawing Circle.

 Derived class Circle object calling center().
Centering Figure...
Erasing Circle.
Drawing Circle.
Drawing Circle.

 myDraw: Derived class object calling center().
Centering Figure...
Erasing Circle.
Drawing Circle.

=======================Explanation for Exercise 2===========================
Without virtual functions the compiler looks at the base class pointer and invokes the base class functions erase and draw. When the virtual functions
are implemented, the compiler uses the derived functions within the specific triangle and circle classes. This is an example of polymorphism.
*/
