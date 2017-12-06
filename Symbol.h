#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef unsigned int uint;

class Symbol
{
private:
	char c;
	int frequency;
	string code;

public:
	Symbol();
	Symbol(char symbol, int freq, string code);
	~Symbol();
	void setSymbol(char symbol);
	void setFrequency(int freq);
	void setCode(string code);
	char getSymbol();
	int getFrequency();
	string getCode();
	void operator++(int);
};

#endif
