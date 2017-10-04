//Zack Nicholson 010318451
//Professor Tarng
//CMPE 50 Lab -- Section 3
//2 February 2017

#include <iostream>
using namespace std;

int square(int num);
int main() {

	//Excercise 1
	cout << "A fool thinks himself to be wise, but a wise man knows himself to be a fool.\n" << endl;

	//Excercise 2
	int number;
	cout<<"Input a number to square: "<<endl;
	cin>>number;
	cout<<square(number)<<endl;

	//Excercise 3
	int i,j, k;
	bool is_prime = true;
	cout<<"Input a integer greater than 2: ";
	cin>>k;
	for (i = 2; i <= k; i++){ //i is the value we are checking is prime
		is_prime=true;
		for (j=2;j<i;j++){ //Check if i does not divide evenly into any other number besides itself.
			if ((i%j) == 0){
				is_prime=false; //If it does divide evenly then it isn't prime. Continue onto next number.
				break;}
		}
		if (is_prime){ //If all numbers parsed had remainders than the current number "i" is prime.
			cout<<i<<", ";}
	}
return 0;
}

int square(int num){
	return num*num;
}

/*
A fool thinks himself to be wise, but a wise man knows himself to be a fool.

Input a number to square:
13
169
Input a integer greater than 2: 66
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
*/
