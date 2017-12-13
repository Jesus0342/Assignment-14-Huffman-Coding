#ifndef HEADER_H_
#define HEADER_H_

#include "Symbol.h"

vector<char> getText(string fileName);

vector<Symbol> getSymbolFrequencies(vector<char> text);

vector<string> encodeText(vector<char> text, vector<Symbol> symbols);

vector<char> decodeText(vector<string> encodedText, vector<Symbol> symbols);

uint symbolExists(char symbol, vector<Symbol> symbols);

#endif
