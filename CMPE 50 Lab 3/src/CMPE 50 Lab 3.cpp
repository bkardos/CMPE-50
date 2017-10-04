//Zackary K. Nicholson
//CMPE 50 Section 1

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iomanip>
using namespace std;

void excercise_1();
void excercise_2();
void excercise_3();
void SelectionSort(int a[], int size);
void varSwap(int &v1, int &v2);
void arySwap(int a[], int size, int index_1, int index_2);
void count_array(int array[], int size, int c_array[], int& c_array_real_size);
void print_count(int c_array[], int c_ary_len, int array[], int size, ofstream &fout);
void print_array(int ary[], int len);
void mergeArray(int ary1[],int ary1_len,int ary2[], int ary2_len,int combined_ary[],int &total_len);

int main() {
	cout<<"Starting Exercise 1..."<<endl;
	excercise_1();
	cout<<"Starting Exercise 2..."<<endl;
	excercise_2();
	cout<<"Starting Exercise 3..."<<endl;
	excercise_3();
}

void excercise_1(){
	int i=0;
	int j=0;
	char a[100];
	char b[100];
	ifstream messy_txt;
	ofstream clean_txt;
	messy_txt.open("D:/Code/C++/CMPE 50 Lab 2/LabInput3-1.txt");
	clean_txt.open("D:/Code/C++/CMPE 50 Lab 2/LabOutput3-1.txt");
	if (messy_txt.fail()){
		cout << "Input file opening failed.\n";
		exit(1);}
	else{
		cout<<"Input file opening successful!"<<endl;
	}
	if (clean_txt.fail()){
		cout << "Output file opening failed.\n";
		exit(1);}
	else{
		cout<<"Output file opening successful!"<<endl;
	}
	cout<<"Parsing input file..."<<endl;
	while(!messy_txt.eof()){
		messy_txt>>a[i];
		i++;}
	cout<<"Array Parsed, cleaning and dumping to output file..."<<endl;
	while(j<i-1){
		b[j]=toupper(a[j]);
		clean_txt<<b[j];
		j++;}
	messy_txt.close();
	clean_txt.close();
	cout<<"End of Excercise 1. Check output file for results.\n\n";
}

void excercise_2(){
	char selector;
	int input_ary[51]={0};
	int ary_count[51]={0};
	int ary_count_len=0;
	int length=0;
	string filename;
	cout<<"Would you like to manually enter an integer list or select a file?\n>>>>Enter m for manual or f for file: ";
	cin>>selector;
	ofstream fout;
	fout.open("D:/Code/C++/CMPE 50 Lab 2/LabOutput3-2.txt");
	if (fout.fail()){
		cout << "Output file opening failed.\n";
		exit(1);}
	else{
		cout<<"Output file opening successful!"<<endl;}
	if (selector=='m'){ //Manual number entry...
		length=0;
		while(true){
			int temp=0;
			cout<<"Input a number or enter \"999\" to stop entering: "<<endl;
			cin>>temp;
			if (temp==999){
				break;}
			else{
				input_ary[length]=temp;
				length++;}
		}
	}

	if (selector=='f'){//Manual Filename entry
		length=0;
		ifstream fin;
		cout<<"Please enter the full filename you would like to parse: "<<endl; //ie: D:/Code/C++/CMPE 50 Lab 2/LabInput3-2.txt
		//cin>>filename;
		filename="D:/Code/C++/CMPE 50 Lab 2/LabInput3-2.txt";
		//Open Input File as fin object
		fin.open(filename.c_str());
		if (fin.fail()){
			cout << "Input file opening failed.\n";
			exit(1);}
		else{
			cout<<"Input file opening successful!"<<endl;}

		//Open Output File as fout object

		while(fin>>input_ary[length]){
			//cout<<input_ary[length];
			length++;}
		fin.close();
		//cout<<length<<endl;
	}
	SelectionSort(input_ary,length);
	count_array(input_ary,length,ary_count,ary_count_len);
	print_count(ary_count,ary_count_len,input_ary,length, fout);
	fout.close();
	cout<<"Exercise 2 completed. The console output will match the file output for this excercise.\n\n";
}

void excercise_3(){
	ifstream fin1;
	ifstream fin2;
	ofstream fout;
	int input_ary1[50];
	int input_ary2[50];
	int combined_ary[100];
	int ary1_len=0;
	int ary2_len=0;
	int combined_ary_len = 0;
	int len=0;
	//Open file one and input to array
	fin1.open("D:/Code/C++/CMPE 50 Lab 2/LabInput3-3.txt");
	if (fin1.fail()){
		cout << "Input file 1 opening failed.\n";
		exit(1);}
	else{
		cout<<"Input file 1 opening successful!"<<endl;}
	while(fin1>>input_ary1[ary1_len]){
		ary1_len++;}
	fin1.close();
	//Open file two and input to array
	fin2.open("D:/Code/C++/CMPE 50 Lab 2/LabInput3-4.txt");
	if (fin2.fail()){
		cout << "Input file 2 opening failed.\n";
		exit(1);}
	else{
		cout<<"Input file 2 opening successful!"<<endl;}
	while(fin2>>input_ary2[ary2_len]){
		ary2_len++;}
	fin2.close();
	mergeArray(input_ary1,ary1_len,input_ary2,ary2_len,combined_ary,combined_ary_len);
	SelectionSort(combined_ary,combined_ary_len);
	fout.open("D:/Code/C++/CMPE 50 Lab 2/LabOutput3-3.txt");
	if (fout.fail()){
		cout << "Output file opening failed.\n";
		exit(1);}
	else{
		cout<<"Output file opening successful!"<<endl;}
	while(len<combined_ary_len){
		fout<<combined_ary[len]<<" ";
		len++;}
	fout.close();
	cout<<"Excercise 3 Completed. Check output file for merged and sorted array."<<endl;
}

void SelectionSort(int a[], int size){
	for (int i=0; i<size; i++){
		int smallest=a[i];
		int min_position=i;
		for (int j=min_position+1;j<size; j++){
			if(a[j]<smallest){
				smallest=a[j];
				min_position=j;}
		}
		arySwap(a, size,i, min_position);
	}
}
void arySwap(int a[], int size, int index_1, int index_2){
	// do not need to swap
	if (index_1 == index_2){
		return;}
	if (index_1 >= size || index_2 >= size){
		return;}
	if (index_1 < 0 || index_2 < 0){
		return;}
	varSwap(a[index_1], a[index_2]);}

void varSwap(int &v1, int &v2){
	int temp;
	temp=v1;
	v1=v2;
	v2=temp;
}

void count_array(int in_ary[],int size,int c_array[],int &c_ary_len){
	int len = 0;
	for (int i = 0;i<size;i++){
		bool exist = false;
		for (int j=0;j<len; j++){ //Parses the sorted array to see if each integer is in the count array
			if (c_array[j]==in_ary[i]){
				exist = true;
				break;}
		}
		if (!exist){
			c_array[len] = in_ary[i];
			len++;}
	}
	c_ary_len = len;
}

void print_count(int c_array[], int c_ary_len, int array[], int size, ofstream &fout){
	cout << "N" << setw(8) << "Count" << endl;
	fout << "N" << setw(8) << "Count" << endl;
	for (int i=c_ary_len-1;i>=0;i--){
		int cur_num = c_array[i];
		int count = 0;
		for (int j = 0; j < size; j++){
			if (array[j]==cur_num){
				count++;}
		}
		cout <<cur_num<< setw(6) << count << endl;
		fout <<cur_num<< setw(6) << count << endl;
	}
}

void mergeArray(int ary1[],int ary1_len,int ary2[], int ary2_len,int combined_ary[],int &total_len){
	total_len=ary1_len+ary2_len;
	int counter=0;
	for (int i=0; i<ary1_len;i++){
		combined_ary[i]=ary1[i];
	}
	for (int j=ary1_len; j<=total_len;j++){
			combined_ary[j]=ary2[counter];
			counter+=1;}
}
void print_array(int ary[], int len){
	for (int i=0; i<len;i++){
		cout<<ary[i]<<" ";}
	cout<<endl;
}


//Console Output/////////////////////////////////////////////////////////////////////////
/*
Starting Exercise 1...
Input file opening successful!
Output file opening successful!
Parsing input file...
Array Parsed, cleaning and dumping to output file...
End of Excercise 1. Check output file for results.

Starting Exercise 2...
Would you like to manually enter an integer list or select a file?
>>>>Enter m for manual or f for file: f
Output file opening successful!
Please enter the full filename you would like to parse:
Input file opening successful!
N   Count
4     2
3     1
1     2
-3     1
Exercise 2 completed. The console output will match the file output for this excercise.

Starting Exercise 3...
Input file 1 opening successful!
Input file 2 opening successful!
Output file opening successful!
Excercise 3 Completed. Check output file for merged and sorted array.

//File Contents

LabOutput3-1.txt
THISASAMPLETESTDATAFILE.

LabOutput3-2.txt
N   Count
4     2
3     1
1     2
-3     1

LabOutput3-3.txt
6 10 15 22 30 33 40 50 60 62 77 88 89 99
