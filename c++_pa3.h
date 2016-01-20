#ifndef PA3_H
#define PA3_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <fstream>
class stacky{
	public: std::vector<char> stackv;
	public: std::vector<std::string> stackv2;
	public: void pushc(char);
	public: char popc();
	public: void pushs(std::string);
	public: std::string pops();
};


#endif
