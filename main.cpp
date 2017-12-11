/******************************************************************************
 * AUTHORS        : Jesus Sanchez
 * ASSIGNMENT #14 : Huffman Coding
 * CLASS          : CS1D
 * SECTION        : MW: 3:00pm
 * DUE DATE       : 12/13/2017
 *****************************************************************************/

#include "Symbol.h"
#include "HuffmanTree.h"

vector<char> getText(string fileName);

vector<Symbol> getSymbolFrequencies(vector<char> text);

vector<string> encodeText(vector<char> text, vector<Symbol> symbols);

vector<char> decodeText(vector<string> encodedText, vector<Symbol> symbols);

uint symbolExists(char symbol, vector<Symbol> symbols);

int main()
{
	cout << "**************************************\n"
		 << "* NAME           : Jesus Sanchez     *\n"
		 << "* ASSIGNMENT #13 : Huffman Coding    *\n"
		 << "* CLASS          : CS1D - MW: 3:00pm *\n"
		 << "* DUE DATE       : 12/13/2017        *\n"
		 <<	"**************************************\n\n"
		 << "DESCRIPTION: \n\n";

	cout << "********************************************\n"
			"* PART A - FREQUENCY TABLE & HUFFMAN CODES *\n"
			"********************************************\n\n";

	// Returns the text in the file.
	vector<char> text = getText("InFile.txt");

	// Determines the frequency of each character in the text.
	vector<Symbol> symbols = getSymbolFrequencies(text);

	HuffmanTree huffTree;

	huffTree.buildEncodingTree(symbols);

	// Prints the frequency table and code for each symbol in the text.
	cout << left
		 << setw(12) << "SYMBOL" << setw(15) << "FREQUENCY" << setw(12) << "CODE"
		 << endl
		 << setw(12) << "------" << setw(15) << "---------" << setw(12) << "----"
		 << endl;

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

	cout << "\n**************************\n"
			"* PART B - ENCODING TEXT *\n"
			"**************************\n\n";

	cout << "Encoding Gettysburg Address...\n\n";

	vector<string> encodedText = encodeText(text, symbols);

	cout << "*************************\n"
			"* PART C - ENCODED TEXT *\n"
			"*************************\n\n";

	cout << "Now printing the encoded Gettysberg Address...\n";

	uint i = 0;

	while(i < encodedText.size())
	{
		string line;

		uint projectedLength = 0;

		while(projectedLength < 76 && i < encodedText.size())
		{
			if(projectedLength + encodedText[i].size() < 76)
			{
				line += encodedText[i];

				projectedLength += encodedText[i].size();

				i++;
			}
			else
			{
				projectedLength = 100;
			}
		}

		cout << line << endl;
	}

	cout << "\n************************************\n"
			"* PART D - DECODED COMPRESSED FILE *\n"
			"************************************\n\n";

	cout << "Now decoding the encoded Gettysberg Address...\n\n";

	vector<char> decodedText = decodeText(encodedText, symbols);

	uint j = 0;

	while(j < decodedText.size())
	{
		string line;

		uint projectedLength = 0;

		while(projectedLength < 76 && j < decodedText.size())
		{
			line += decodedText[j];

			if(decodedText[j] == '\n')
			{
				projectedLength = 100;
			}
			else
			{
				projectedLength++;
			}

			j++;
		}

		if(line.back() != '\n' && line.back() != '.' && line.back() != '!')
		{
			if(line.back() != ' ')
			{
				while(line.back() != ' ' && !line.empty())
				{
					line.pop_back();

					j--;
				}
			}
		}

		if(!line.empty())
		{
			cout << line << endl;
		}
		else
		{
			cout << "Check ending puncutation!!\n\n";
		}
	}

	cout << "\n******************************\n"
			"* PART E - COMPRESSION RATIO *\n"
			"******************************\n\n";

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
