#include "HuffmanTree.h"

HuffmanTree::HuffmanTree()
{
}


HuffmanTree::~HuffmanTree()
{
}

void HuffmanTree::buildEncodingTree(vector<Symbol> &symbols)
{
	//Declares the new node in the Encoding Tree that will become the parent of
	// the elements with the lowest frequency and its left and right children.
	NodeType *left, *right, *top;

	// Defines a priority queue storing the symbols.
	priority_queue<NodeType*, vector<NodeType*>, CompareFrequency> nodeQueue;

	// Stores the symbols in the priority queue in increasing order.
	for(uint i = 0; i < symbols.size(); i++)
	{
		nodeQueue.push(new NodeType(symbols[i].getSymbol(), symbols[i].getFrequency()));
	}

	// Makes the symbols with the lowest frequencies the children of top and
	// adds top back onto the queue.
	while(nodeQueue.size() != 1)
	{
		// Makes the node with the lowest frequency the left child of top.
		left = nodeQueue.top();
		nodeQueue.pop();

		// Makes the node with the next lowest frequency the right child of top.
		right = nodeQueue.top();
		nodeQueue.pop();

		// Creates a new node for top and makes its frequency the sum of its
		// children's frequencies and makes its left and right pointers point
		// to its left and right children.
		top = new NodeType('`', left->freq + right->freq);
		top->left = left;
		top->right = right;

		// Pushes top back onto the priority queue with its new frequency.
		nodeQueue.push(top);
	}

	// Generates the codes for all of the symbols in the Encoding Tree.
	generateCodes(nodeQueue.top(), "", symbols);
}

void HuffmanTree::generateCodes(NodeType* root, string code, vector<Symbol> &symbols)
{
	// Base Case - Breaks out of the recursive call if the left or right child
	//             from the previous call is NULL (bottom of tree was reached).
	if(!root)
	{
		return;
	}

	// Stores the code of the symbol.
	if(root->data != '`')
	{
		symbols[getSymbolIndex(root->data, symbols)].setCode(code);
	}

	// Adds a 0 to the current code when going left down the tree.
	generateCodes(root->left, code + "0", symbols);

	// Adds a 1 to the current code when going right down the tree.
	generateCodes(root->right, code + "1", symbols);
}

uint HuffmanTree::getSymbolIndex(char symbol, vector<Symbol> symbols)
{
	// Stores the index of the symbol being search for.
	uint i = 0;

	// Increments i until the symbol is found.
	while(symbol != symbols[i].getSymbol())
	{
		i++;
	}

	return i;
}
