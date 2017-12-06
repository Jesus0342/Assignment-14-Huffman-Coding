#include "HuffmanTree.h"

HuffmanTree::HuffmanTree()
{

}


HuffmanTree::~HuffmanTree()
{

}

void HuffmanTree::buildEncodingTree(vector<Symbol> &symbols)
{
	NodeType *left, *right, *top;

	priority_queue<NodeType*, vector<NodeType*>, CompareFrequency> nodeQueue;

	for(uint i = 0; i < symbols.size(); i++)
	{
		nodeQueue.push(new NodeType(symbols[i].getSymbol(), symbols[i].getFrequency()));
	}

	while(nodeQueue.size() != 1)
	{
		left = nodeQueue.top();
		nodeQueue.pop();

		right = nodeQueue.top();
		nodeQueue.pop();

		top = new NodeType('$', left->freq + right->freq);
		top->left = left;
		top->right = right;

		nodeQueue.push(top);
	}

	generateCodes(nodeQueue.top(), "", symbols);
}

void HuffmanTree::generateCodes(NodeType* root, string code, vector<Symbol> &symbols)
{
	if(!root)
	{
		return;
	}

	if(root->data != '$')
	{
		uint symbolId = getSymbolIndex(root->data, symbols);

		symbols[symbolId].setCode(code);
	}

	generateCodes(root->left, code + "0", symbols);
	generateCodes(root->right, code + "1", symbols);
}

uint HuffmanTree::getSymbolIndex(char symbol, vector<Symbol> symbols)
{
	uint i = 0;

	while(symbol != symbols[i].getSymbol())
	{
		i++;
	}

	return i;
}
