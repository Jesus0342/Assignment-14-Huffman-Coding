#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_

#include "Symbol.h"

struct NodeType
{
	char data;              // Symbol
	int freq;               // Frequency of the symbol
	NodeType *left, *right; // Left and right children of the node.

	// Overloaded constructor.
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

/******************************************************************************
 * CLASS - Huffman Tree
 * ----------------------------------------------------------------------------
 * This class defines a Huffman Tree that is capable of building an Encoding
 * Tree, generating the codes for the symbols in the Encoding Tree, encoding a
 * given text, and decoding the text.
 *****************************************************************************/
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
