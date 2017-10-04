/*
 * Pairs.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: Lt_Ballzacki
 */

#include "Pairs.h"
#include <fstream>
#include <iostream>
using namespace std;

Pairs::Pairs(){
	f=0;
	s=0;}

Pairs::Pairs(int first){
	f=first;
	s=0;}
Pairs::Pairs(int first,int second){
	f=first;
	s=second;}
int Pairs::get_first(){
	return f;}
int Pairs::get_second(){
	return s;}

ostream &operator<<(ostream& os, Pairs &second){
	os<<'(';
	os<<second.f;
	os<<',';
	os<<second.s;
	os<<')';
	return os;}

istream &operator>>(istream &in, Pairs &second){
	char ch;
	in>>ch; //Discard initial '('
	in>>second.f;
	in>>ch; //Discard comma ','
	in>>second.s;
	in>>ch; //Discard final '('
	return in;
}
Pairs operator +(const Pairs &left, const Pairs &right){
	Pairs temp;
	temp.f=left.f+right.f;
	temp.s=left.s+right.s;
	return temp;
}

Pairs operator *(int mult, const Pairs &right){
	Pairs temp;
	temp.f=mult*right.f;
	temp.s=mult*right.s;
	return temp;
}
