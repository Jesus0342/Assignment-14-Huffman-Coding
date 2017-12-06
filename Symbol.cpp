#include "Symbol.h"

Symbol::Symbol()
{
	c = ' ';
	frequency = 0;
	code = "";
}

Symbol::Symbol(char symbol, int freq, string code)
{
	c = symbol;
	frequency = freq;
	this->code = code;
}

Symbol::~Symbol()
{

}

void Symbol::setSymbol(char symbol)
{
	c = symbol;
}

void Symbol::setFrequency(int freq)
{
	frequency = freq;
}

void Symbol::setCode(string code)
{
	this->code = code;
}

char Symbol::getSymbol()
{
	return c;
}

int Symbol::getFrequency()
{
	return frequency;
}

string Symbol::getCode()
{
	return code;
}

void Symbol::operator++(int)
{
	frequency++;
}
