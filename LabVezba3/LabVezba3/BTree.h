#pragma once
#include "BNode.h"
#define COUNT 5

class BTree
{
public:
	BNode* root;
	int numEl;
public:
	BTree()
	{
		root = NULL;
		numEl = 0;
	}
	~BTree()
	{
		deleteTree(root);
	}
protected:
	void deleteTree(BNode* p)
	{

		if (p != NULL)
		{
			deleteTree(p->left);
			deleteTree(p->right);
			delete p;
		}
	}

	
public:
	
	void print2DUtil(BNode* root, int space)
	{
		// Base case
		if (root == NULL)
			return;

		// Increase distance between levels
		space += COUNT;

		// Process right child first
		print2DUtil(root->right, space);

		// Print current node after space
		// count
		cout << endl;
		for (int i = COUNT; i < space; i++)
			cout << " ";
		if (root->info == -1) {
			cout << root->weight << "\n";
		}
		else {
			cout << root->weight << " " << root->info << "\n";
		}
		
		// Process left child
		print2DUtil(root->left, space);
	}
	void print2D(BNode* root)
	{
		// Pass initial space count as 0
		print2DUtil(root, 0);
	}


};

