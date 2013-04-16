#include "BTree.h"

int main()
{
	/*
		BTree *tree = new BTree<int, char>
	*/
	BTreeNode<int, double> *node = new BTreeNode<int, double>(2);

	delete node;

	return 0;
}