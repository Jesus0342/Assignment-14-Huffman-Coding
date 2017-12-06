#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_

#include "Symbol.h"

struct NodeType
{
	char data;              // Symbol (character, space, newline, etc.)
	int freq;              // Frequency of the symbol
	NodeType *left, *right; // Left and right children.

	NodeType(char data, int freq)
	{
		this->data = data;
		this->freq = freq;
		left = NULL;
		right = NULL;
	}
};

class CompareFrequency
{
public:
	bool operator()(NodeType *node, NodeType *otherNode)
	{
		return (node->freq > otherNode->freq);
	}
};

class HuffmanTree
{
public:
	HuffmanTree();
	~HuffmanTree();
	void buildEncodingTree(vector<Symbol> &symbols);
	void generateCodes(NodeType* root, string code, vector<Symbol> &symbols);

private:
	uint getSymbolIndex(char symbol, vector<Symbol> symbols);
};

#endif
