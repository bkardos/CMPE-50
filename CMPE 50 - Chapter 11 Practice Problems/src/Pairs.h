#ifndef PAIRS_H_
#define PAIRS_H_
#include <iostream>
#include <fstream>
using namespace std;

class Pairs{
	public:
		Pairs();
		Pairs(int first);
		Pairs(int first, int second);
		int get_first();
		int get_second();
		friend istream &operator>>(istream &in, Pairs &second);
		friend ostream &operator <<(ostream &os, Pairs &second);
		friend Pairs operator +(const Pairs &left, const Pairs &right);
		friend Pairs operator *(int mult, const Pairs &right);
	private:
		int f;
		int s;
};

#endif /* PAIRS_H_ */
