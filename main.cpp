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
	vector<char> text = getText("InFile.txt");

	vector<Symbol> symbols = getSymbolFrequencies(text);

	for(uint i = 0; i < text.size(); i++)
	{
		cout << text[i];
	}

	cout << endl;

	for(uint i = 0; i < symbols.size(); i++)
	{
		cout << symbols[i].getSymbol() << " :" << symbols[i].getFrequency(); cout << endl;
	}

	cout << endl;

	HuffmanTree test;

	test.buildEncodingTree(symbols);

	cout << endl;

	for(uint i = 0; i < symbols.size(); i++)
	{
		cout << symbols[i].getSymbol() << " :" << symbols[i].getCode(); cout << endl;
	}

	cout << endl;

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
