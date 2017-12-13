#include "Header.h"

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

vector<string> encodeText(vector<char> text, vector<Symbol> symbols)
{
	vector<string> encodedText;

	// Huffman code of the current character.
	string currCode;

	for(uint i = 0; i < text.size(); i++)
	{
		encodedText.push_back(symbols[symbolExists(text[i], symbols)].getCode());
	}

	return encodedText;
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

vector<char> decodeText(vector<string> encodedText, vector<Symbol> symbols)
{
	vector<char> decodedText;

	for(uint i = 0; i < encodedText.size(); i++)
	{
		bool found = false;

		uint j = 0;

		while(j < symbols.size() && !found)
		{
			if(encodedText[i] == symbols[j].getCode())
			{
				found = true;
			}
			else
			{
				j++;
			}
		}

		decodedText.push_back(symbols[j].getSymbol());
	}

	return decodedText;
}
