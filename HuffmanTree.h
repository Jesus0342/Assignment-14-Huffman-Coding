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

/******************************************************************************
 * COMPARATOR CLASS - CompareFrequency
 * ----------------------------------------------------------------------------
 * This class is used to store the symbols in the Symbols vector in the priority
 * queue in ascending order.
 *****************************************************************************/
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
	// Default constructor.
	HuffmanTree();

	// Destructor.
	~HuffmanTree();

	// Builds the encoding tree using the symbols stored in the Symbol vector
	// and generates their Huffman Codes.
	// PRE-CONDITION:
	// symbols - Vector of symbols with their frequencies must be defined.
	// POST-CONDITION:
	// The Huffman Codes for each of the symbols will be stored.
	void buildEncodingTree(vector<Symbol> &symbols);

	// Recursively generates the codes for each of the symbols in the symbol vector.
	// PRE-CONDITIONS:
	// root - Pointer to the current node in the Huffman Tree.
	// code - Huffman Code of the symbol.
	// symbols - Vector of symbols.
	// POST-CONDITION:
	// Stores the Huffman Code for each symbol.
	void generateCodes(NodeType* root, string code, vector<Symbol> &symbols);

private:
	// Returns the index of the symbol being searched for.
	// PRE-CONDITIONS:
	// symbol - Symbol to be searched for.
	// symbols - Vector of symbols.
	uint getSymbolIndex(char symbol, vector<Symbol> symbols);
};

#endif
