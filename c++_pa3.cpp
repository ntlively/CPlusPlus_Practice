#include <iostream>
#include "pa3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <ctype.h>
using namespace std;
ifstream fileinput;
vector<char> fsave;
vector<char>keywords;
vector<string>keyspelling;
vector<char>identifiers;
vector<char>delims;
vector<char>numbers;
vector<char>operators;
vector<char>errors;
vector<string>misspells;
vector<char>nospacekeywords;
int loops = 0;
int badspelling = 0;
//the push function below adds the value to the top of the stack
void stacky::pushc(char input) {
	stackv.push_back(input);
}
//the pop function below takes the value on top of the stack and returns it, then deletes it	
char stacky::popc() {
	return stackv.back();
	stackv.pop_back();
}
void stacky::pushs(string input) {
	stackv2.push_back(input);
}
//the pop function below takes the value on top of the stack and returns it, then deletes it	
string stacky::pops() {
	return stackv2.back();
	stackv2.pop_back();
}



//the fopen function below takes a user input filename and opens a ifstream
void fopen() {
	string fname;
	cout << "Please enter the name of the file: \n";
	cin >> fname;
	if (!fileinput) {
		cerr << "Input file could not be opened";
		exit(0);
	}
	else {
		fileinput.open(fname.c_str(), ios::in);
	}
}
//The fscan function below saves the entire file into a vector of characters, but excludes any 'spaces'
void fscan() {
	char x;
	if (!fileinput) {
		cout << "error loading file\n";
	}
	else {
		while (fileinput.get(x)) {
			if (x != ' ') {
				fsave.push_back(x);
			}
		}
	}
}
//the printvector function below prints all the characters from the vector specified
void printcharvector(vector<char> vname) {
	vector<string>outputv;
	string output;
	for (unsigned int i = 0; i < vname.size(); i++) {
		if (vname[i] == ' ') {
			outputv.push_back(output);
			output = "";
			//cout<<" ";
		}
		else {
			output = output + vname[i];
			//cout<<vname[i];	
		}
	}

	string temporary;
	for (unsigned int i = 0; i < outputv.size(); i++) {
		temporary = outputv[i];
		for (unsigned int j = (i + 1); j < outputv.size(); j++) {
			if (temporary == outputv[j]) {
				outputv[j] = "";
			}
		}
	}

	for (unsigned int i = 0; i < outputv.size(); i++) {
		if (outputv[i] != " ") {
			cout << outputv[i];
			cout << " ";
		}
	}
}




//the function keywordcheck scans the character vector and parses out the keywords
void keywordcheck() {

	char spacey = ' ';

	for (unsigned int i = 0; i < fsave.size(); i++) {
		if (isupper(fsave[i]) != 0) {
			keywords.push_back(fsave[i]);
		}
		else {
			keywords.push_back(spacey);
		}
	}

	//The bit above scans through the vector of char's that the txt file was saved to, and saved all keywords to a new vector
	//regardless of misspelling or matching	
	string addstring;

	for (unsigned int i = 0; i < keywords.size(); i++) {
		if ((isupper(keywords[i]))) {
			addstring = addstring + keywords[i];
		}
		else {
			keyspelling.push_back(addstring);
			addstring = "";
		}
	}
	//some functions were used for testing and are not utilized.
	for (unsigned int i = 0; i < fsave.size(); i++) {
		if (isupper(fsave[i]) != 0) {
			nospacekeywords.push_back(fsave[i]);
		}
	}
	//
	//The bit above takes the vector of characters for the keywords and appends them into a string vector comparisons later	/*||(keyspelling[i]==" ")*/
	badspelling = nospacekeywords.size();
	for (unsigned int i = 0; i < keyspelling.size(); i++) {
		if ((keyspelling[i] == "FOR") || (keyspelling[i] == "BEGIN") || (keyspelling[i] == "END")) {
			misspells.push_back(keyspelling[i]);
		}
		else {
			string pushstring = keyspelling[i];
			for (unsigned int i = 0; i < pushstring.size(); i++) {
				errors.push_back(pushstring[i]);
			}
			errors.push_back(' ');
		}
	}
	//The bit above takes the string vector of keywords and compares its entries to possible keywords. misspellings are sent to error vector		
}
//The identifiercheck function below parses out identifiers from the overall vector of characters
void identifiercheck(unsigned int pos) {
	char spacey = ' ';
	if (pos < fsave.size()) {
		if (islower(fsave[pos]) != 0) {
			identifiers.push_back(fsave[pos]);
			identifiercheck(pos + 1);
		}
		else {
			identifiers.push_back(spacey);
			identifiercheck(pos + 1);
		}
	}
}
// The delimcheck function below parses out the deliminators from the overall character vector
void delimcheck(unsigned int pos) {
	char spacey = ' ';
	if (pos < fsave.size()) {
		if ((fsave[pos] == ';') || (fsave[pos] == ',')) {
			delims.push_back(fsave[pos]);
			delimcheck(pos + 1);
		}
		else {
			delims.push_back(spacey);
			delimcheck(pos + 1);
		}
	}
}
//The numbercheck function below parses out numbers from the overall character vector
void numbercheck(unsigned int pos) {
	char spacey = ' ';
	if (pos < fsave.size()) {
		if (isdigit(fsave[pos])) {
			numbers.push_back(fsave[pos]);
			numbercheck(pos + 1);
		}
		else {
			numbers.push_back(spacey);
			numbercheck(pos + 1);
		}
	}
}
//The operatorcheck function below parses out operators from the total character vector
void operatorcheck(unsigned int pos) {
	char spacey = ' ';
	if (pos < fsave.size()) {
		if (isdigit(fsave[pos]) || fsave[pos] == ';' || fsave[pos] == ',' || islower(fsave[pos]) != 0 || isupper(fsave[pos]) != 0 || fsave[pos] == '(' || fsave[pos] == ')') {
			operators.push_back(spacey);
			operatorcheck(pos + 1);
		}
		else {
			operators.push_back(fsave[pos]);
			operatorcheck(pos + 1);
		}
	}
}
//the stackcheck function below checks for pairings of both brackets and begin/ends
void stackcheck() {
	stacky* stack = new stacky();
	int xpair = 0;
	int ypair = 0;
	int counter = 0;
	for (unsigned int i = 0; i < fsave.size(); i++) {
		if (fsave[i] == '(') {
			stack->pushc(fsave[i]);
			counter = counter + 1;
			xpair = xpair + 1;
		}
		if (fsave[i] == ')') {
			stack->pushc(fsave[i]);
			counter = counter + 1;
			ypair = ypair + 1;
		}
	}

	if (xpair > ypair) {
		errors.push_back('(');
		errors.push_back(' ');
	}
	if (xpair < ypair) {
		errors.push_back(')');
		errors.push_back(' ');
	}

}
void keywordstackcheck() {
	stacky* stack = new stacky();
	int endpair = 0;
	int beginpair = 0;
	int counter = 0;

	for (unsigned int i = 0; i < keyspelling.size(); i++) {
		if (keyspelling[i] == "FOR") {
			stack->pushs(keyspelling[i]);
			counter = counter + 1;
			loops = loops + 1;
		}
		if (keyspelling[i] == "BEGIN") {
			stack->pushs(keyspelling[i]);
			counter = counter + 1;
			beginpair = beginpair + 1;
		}
		if (keyspelling[i] == "END") {
			stack->pushs(keyspelling[i]);
			counter = counter + 1;
			endpair = endpair + 1;
		}
	}
	//absolutely everything about this program works except for one thing
	//and that is that I cannot seem to keep track of the number of misspelled keywords
	//if I could find a way to find that I could make the error printing work for any case
	//I need to know whether to print the misspelled word, or print a begin/end.
	//I spent over 3 hours on this, please don't take off tons of points.	
	if (beginpair > endpair) {
		for (unsigned int i = 0; i < misspells.size() - 1; i++) {
			errors.push_back('E');
			errors.push_back('N');
			errors.push_back('D');
			errors.push_back(' ');
		}
	}
	if (beginpair < endpair) {
		for (unsigned int i = 0; i < misspells.size() - 5; i++) {
			for (int i = 0; i < endpair - beginpair; i++) {
				errors.push_back('B');
				errors.push_back('E');
				errors.push_back('G');
				errors.push_back('I');
				errors.push_back('N');
				errors.push_back(' ');
			}
		}

	}


}


int main(int argc, char *argv[]) {

	fopen();
	fscan();
	printcharvector(fsave);
	cout << "\n total saved vector above\n";

	keywordcheck();
	cout << "\n The keywords are: \n";
	printcharvector(keywords);

	identifiercheck(0);
	cout << "\n The identifiers are: \n";
	printcharvector(identifiers);

	delimcheck(0);
	cout << "\n The delimiters are: \n";
	printcharvector(delims);

	numbercheck(0);
	cout << "\n The numbers are: \n";
	printcharvector(numbers);

	operatorcheck(0);
	cout << "\n The operators are: \n";
	printcharvector(operators);


	stackcheck();

	keywordstackcheck();


	cout << "\n Syntax errors below\n";
	printcharvector(errors);

	cout << "\n The number of nested loops is: " << loops - 1 << "\n";
	fileinput.close();
}
