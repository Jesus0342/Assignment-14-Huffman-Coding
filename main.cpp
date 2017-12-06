/******************************************************************************
 * AUTHORS        : Jesus Sanchez
 * ASSIGNMENT #14 : Huffman Coding
 * CLASS          : CS1D
 * SECTION        : MW: 3:00pm
 * DUE DATE       : 11/29/2017
 *****************************************************************************/

#include "Symbol.h"
#include "HuffmanTree.h"

vector<char> getText(string fileName);

vector<Symbol> getSymbolFrequencies(vector<char> text);

uint symbolExists(char symbol, vector<Symbol> symbols);

int main()
{
	cout << "\n********************************************\n"
			"* PART A - FREQUENCY TABLE & HUFFMAN CODES *\n"
			"********************************************\n\n";

	// Returns the text in the file.
	vector<char> text = getText("InFile.txt");

	vector<Symbol> symbols = getSymbolFrequencies(text);

	HuffmanTree test;

	test.buildEncodingTree(symbols);

	// Prints the frequency table and code for each symbol in the text.
	cout << left
		 << setw(12) << "SYMBOL" << setw(15) << "FREQUENCY" << setw(12) << "CODE" << endl;
	cout << setw(12) << "------" << setw(15) << "---------" << setw(12) << "----" << endl;

	for(uint i = 0; i < symbols.size(); i++)
	{
		if(symbols[i].getSymbol() == ' ')
		{
			cout << setw(12) << " space";
		}
		else if(symbols[i].getSymbol() == '\n')
		{
			cout << setw(12) << "  \\n";
		}
		else
		{
			cout << "   " << setw(9) << symbols[i].getSymbol();
		}

		cout << "   " << setw(12) << symbols[i].getFrequency()
								  << symbols[i].getCode() << endl;
	}

	cout << "\n****************************************\n"
			"* PART B - ENCODING GETTYSBURG ADDRESS *\n"
			"****************************************\n\n";

	cout << "Encoding Gettysburg Address...\n";

	cout << "\n***************************************\n"
			"* PART C - ENCODED GETTYSBURG ADDRESS *\n"
			"***************************************\n\n";

	return 0;
}

vector<char> getText(string fileName)
{
	vector<char> text;

	char symbol;

	ifstream fin;

	fin.open(fileName.c_str());

	while(fin.get(symbol))
	{
		text.push_back(symbol);
	}

	return text;
}

vector<Symbol> getSymbolFrequencies(vector<char> text)
{
	vector<Symbol> symbols;

	for(uint i = 0; i < text.size(); i++)
	{
		uint symIndex = symbolExists(text[i], symbols);

		if(symIndex >= symbols.size())
		{
			Symbol temp(text[i], 1, "");

			symbols.push_back(temp);
		}
		else
		{
			symbols[symIndex]++;
		}
	}

	return symbols;
}

uint symbolExists(char symbol, vector<Symbol> symbols)
{
	uint i = 0;

	bool found = false;

	while(i < symbols.size() && !found)
	{
		if(symbols[i].getSymbol() == symbol)
		{
			found = true;
		}
		else
		{
			i++;
		}
	}

	return i;
}
