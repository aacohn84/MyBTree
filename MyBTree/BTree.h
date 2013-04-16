/*
	B-Tree properties:
		1. A node x has the following attributes:
			x.n is the number of keys in the node
			the keys are stored in nondecreasing order (x.key_1 <= x.key_2 <= ... <= x.key_n)
			x.leaf is a boolean which is TRUE if the node is a leaf, otherwise FALSE
		
		2. Each node also contains x.n + 1 child pointers (x.c_1, x.c_2, ..., x.c_(n+1))
			Leaf nodes have no children, so their c_i pointers are undefined.
		
		3. If k_i is any key stored in the subtree with root x.c_i, then
			k_1 <= x.key_1 <= k_2 <= x.key_2 <= ... <= x.key_x.n <= k_x.n+1

		4. All leaves have the same depth, which is the tree's height, h.

		5. Nodes have lower and upper bounds on the number of keys they can contain.
			We express these bounds in terms of a fixed integer t >= 2 called the
			minimum degree of the B-tree:

			a. Every node other than the root must have at least t - 1 keys. Every
			internal node other than the root thus has at least t children. If the
			tree is nonempty, the root must have at least one key.

			B. Every node may contain at most 2t-1 keys. Therefore, an internal node
			may have at most 2t children. We say that a node is full if it contains
			exactly 2t-1 keys.


		
*/
#pragma once
#define DEBUGMODE 1

#if DEBUGMODE
#include <cassert>
#endif

#ifndef NULL
#define NULL 0
#endif

template <class Key, class Data>
class BTreeNode
{
public:
	typedef BTreeNode<Key, Data>* Ptr;

	int n; // logical # of keys stored in the node
	bool leaf; // initially false
	Key key;
	Data data;
	Ptr *c; // dynamically allocated array
	
	BTreeNode(int t)
		: n(0), leaf(true)
	{
		c = new Ptr[2*t - 1]();
	}

	BTreeNode(int t, Key key, Data data, bool leaf)
		: n(0), key(key), data(data), leaf(leaf)
	{
		c = new Ptr[2*t - 1]();
	}
	
	~BTreeNode()
	{
		#if DEBUGMODE
		int nChildren = sizeof(c) / sizeof(Ptr);
		for (int i = 0; i < nChildren; i++)
			assert(c[i] == NULL);
		#endif
		
		delete [] c;
	}
};

template <class Key, class Data>
class BTree
{
public:
	BTreeNode::Ptr root;
	BTree(void);
	~BTree(void);
};
