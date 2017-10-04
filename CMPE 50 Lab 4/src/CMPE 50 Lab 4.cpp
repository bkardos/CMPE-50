// Author: Zack Nicholson
// Class: CMPE 50 Section 1
// Date: 3/2/2017
// Lab #: 4

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

void exercise_1();
void exercise_2();

void read_array(char input[], int size);
void print_array(char array[], int size);
bool check(string& sentence, int& position, string src, string dest);
bool check_end(char ch);

int main(){
	exercise_1();
	cout<<">>>Exercise 1 completed, continuing to exercise 2..."<<endl;
	exercise_2();
	return 0;
}

void exercise_1()
{
	char input[MAX_SIZE + 1];
	cout << "Please enter a sentence ending with a period:" << endl;
	read_array(input, MAX_SIZE + 1);
	print_array(input, MAX_SIZE + 1);
}

void read_array(char input[], int size){
	bool skip_space = false;
	int i = 0; //i is current character.
	char ch;
	cin.get(ch); //Read in sentence to char array ch.

	while (i<size-2 && ch!='.'){ //Once the loop hits a period the loop ends.
		if (isspace(ch)){
			if (i == 0){
				skip_space = true;}
			else{
				if (!skip_space){
					input[i] = ' ';
					skip_space = true;
					i++;}
			}
		}
		else{
			if (i==0){
				input[i] = toupper(ch);} //First character of a sentence to uppercase.
			else{
				input[i] = tolower(ch);} //Other characters of a sentence to lowercase.
			i++;
			skip_space = false;}
		cin.get(ch);
	} //End of Loop
	input[i] = '.';
	i++;
	input[i] = '\0';
	cin.clear();
}

void print_array(char array[], int size){
	int i = 0;
	while (i < size && array[i] != '\0'){
		cout << array[i];
		i++;}
	cout << endl;
}

///////////////////////////////////////////////////////////////////////
void exercise_2(){

	while (true){
		string sentence;
		int position = 0;
		cout << "Please input a sentence. Enter \"exit\" to end program:" << endl;
		getline(cin,sentence); //Use getline instead of reading one char at a time.
		if (sentence=="Exit"||sentence=="exit"){
			cout << "Program Terminating...\nThank you for using Nicholson Code." << endl;
			return;}

		while(check(sentence, position, "she", "she or he"));
		position = 0;
		while(check(sentence, position, "he", "she or he"));
		position = 0;
		while(check(sentence, position, "He", "She or he"));
		position = 0;
		while(check(sentence, position, "She", "She or he"));
		position = 0;
		while(check(sentence, position, "him", "her or him"));
		position = 0;
		while(check(sentence, position, "her", "her or him"));
		position = 0;
		while(check(sentence, position, "his", "hers, or his"));
		position = 0;
		while(check(sentence, position, "hers", "hers, or his"));
		position = 0;
		while(check(sentence, position, "His", "Hers, or his"));
		position = 0;
		while(check(sentence, position, "Hers", "Hers, or his"));
		cout<< "\nSuggestion:"<<endl;
		cout<<sentence<<endl;
	}
}

bool check(string& sentence, int& position, string src, string dest){
//Checks the input string sentence for a phrase, src, and then puts the suggestion, dest, as a replacement.

	size_t found, found1, found2;  //size_t is unsigned type that can hold an array index
	found = false;
	int size1 = src.size();
	int size2 = dest.size();
	found1 = sentence.find(src, position);
	found2 = sentence.find(dest, position);

	if (found1 != string::npos){ //The source was found.
		if (found2 != string::npos && found1 == found2){ //If the Destination was found and the destination index
			position = found1 + size2;}
		else{
			if (found1 == 0){
				if ((found1 + size1) == sentence.size()){
					found = true;}
				else{
					if (check_end(sentence.at(found1 + size1))){
						found = true;}
				}
			}
			else{
				if (check_end(sentence.at(found1 - 1))){
					if ((found1 + size1) == sentence.size()){
						found = true;}
					else{
						if (check_end(sentence.at(found1 + size1))){
							found = true;}
					}
				}
			}
			if (found){
				cout<<"Found \""<<src<<"\" which should be replaced with \"" <<dest<< "\"" << endl;
				sentence.replace(found1, size1, dest);
				position = found1 + size2;}
			else{
				position = found1 + size1;}
		}
		return true;
	}
	return false; //The source wasn't found.
}

bool check_end(char ch){
	return (ch==' '||ch==','||ch=='.');
}

//////////////////////////////////////////////////////////////
/*

Code Output...

Please enter a sentence ending with a period:
   noW  iS   thE    TiMe  fOr  aLl
         gOOD MEN TO  ComE TO   tHe
  		aId
oF


   ThE  CounTRY.
Now is the time for all good men to come to the aid of the country.
>>>Exercise 1 completed, continuing to exercise 2...
Please input a sentence. Enter "exit" to end program:

Suggestion:

Please input a sentence. Enter "exit" to end program:
See an adviser, talk to him, and listen to him.
Found "him" which should be replaced with "her or him"
Found "him" which should be replaced with "her or him"

Suggestion:
See an adviser, talk to her or him, and listen to her or him.
Please input a sentence. Enter "exit" to end program:
exit
Program Terminating...
Thank you for using Nicholson Code.
*/
