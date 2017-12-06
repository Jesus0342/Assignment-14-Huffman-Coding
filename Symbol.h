#ifndef SYMBOL_H_
#define SYMBOL_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// Redefines the unsigned int type to uint.
typedef unsigned int uint;

/******************************************************************************
 * CLASS - Symbol
 * ----------------------------------------------------------------------------
 * This class defines an object representing a symbol in the Huffman Coding
 * Algorithm and holds its frequency and Huffman Code.
 *****************************************************************************/
class Symbol
{
private:
	char c;        // Symbol
	int frequency; // Frequency of the symbol
	string code;   // Symbol Huffman code

public:
	/**************************************************************************
	 * Class Constructor
	 *************************************************************************/
	Symbol();

	/**************************************************************************
	 * Class Overloaded Constructor
	 * ------------------------------------------------------------------------
	 * Sets the data members of the Symbol object to the values of declared at
	 * object instantiation.
	 *************************************************************************/
	Symbol(char symbol, int freq, string code);

	/**************************************************************************
	 * Class Destructor
	 *************************************************************************/
	~Symbol();

	/**************************************************************************
	 * setSymbol
	 * ------------------------------------------------------------------------
	 * Sets the symbol of the Symbol object.
	 * ------------------------------------------------------------------------
	 * PRE-CONDITION:
	 *     symbol - Symbol must be defined.
	 *
	 * POST-CONDITION:
	 * 	   Changes the symbol data member of the Symbol object.
	 *************************************************************************/
	void setSymbol(char symbol);

	/**************************************************************************
	 * setFrequency
	 * ------------------------------------------------------------------------
	 * Sets the frequency of the Symbol object.
	 * ------------------------------------------------------------------------
	 * PRE-CONDITION:
	 *     frequency - Frequency must be defined.
	 *
	 * POST-CONDITION:
	 * 	   Changes the frequency data member of the Symbol object.
	 *************************************************************************/
	void setFrequency(int freq);

	/**************************************************************************
	 * setCode
	 * ------------------------------------------------------------------------
	 * Sets the code of the Symbol object.
	 * ------------------------------------------------------------------------
	 * PRE-CONDITION:
	 *     code - Code must be defined.
	 *
	 * POST-CONDITION:
	 * 	   Changes the code data member of the Symbol object.
	 *************************************************************************/
	void setCode(string code);

	/**************************************************************************
	 * getSymbol
	 * ------------------------------------------------------------------------
	 * Returns the symbol of the Symbol object.
	 * ------------------------------------------------------------------------
	 * POST-CONDITION:
	 * 	   Symbol of the Symbol object is returned.
	 *************************************************************************/
	char getSymbol();

	/**************************************************************************
	 * getFrequency
	 * ------------------------------------------------------------------------
	 * Returns the frequency of the Symbol object.
	 * ------------------------------------------------------------------------
	 * POST-CONDITION:
	 * 	   Frequency of the Symbol object is returned.
	 *************************************************************************/
	int getFrequency();

	/**************************************************************************
	 * getCode
	 * ------------------------------------------------------------------------
	 * Returns the code of the Symbol object.
	 * ------------------------------------------------------------------------
	 * POST-CONDITION:
	 * 	   Code of the Symbol object is returned.
	 *************************************************************************/
	string getCode();

	/**************************************************************************
	 * operator++
	 * ------------------------------------------------------------------------
	 * Overloads the postfix operator to increment the frequency data member of
	 * the Symbol object.
	 * ------------------------------------------------------------------------
	 * POST-CONDITION:
	 * 	   Frequency ofthe Symbol object is incremented by 1.
	 *************************************************************************/
	void operator++(int);
};

#endif
