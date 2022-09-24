#pragma once
#include <iostream>

using namespace std;

class BNode
{
public:
	char info;
	int weight;
	BNode* left, * right;

public:
	BNode()
	{
		info = -1;
		weight = 0;
		left = right = NULL;

	}
	BNode(char i)
	{
		info = i;
		weight = 0;
		left = right = NULL;
	}
	BNode(int i)
	{
		info = -1;
		weight = i;
		left = right = NULL;
	}


	BNode(char i, int w)
	{
		info = i;
		weight = w;
		left = right = NULL;
	}

	BNode(char i, BNode* l)
	{
		info = i;
		left = l;
		weight = 0;
		right = NULL;
	}

	BNode(char i, BNode* l, BNode* r)
	{
		info = i;
		weight = 0;
		left = l;
		right = r;
	}


	BNode(char i, int w, BNode* l, BNode* r)
	{
		info = i;
		weight = w;
		left = l;
		right = r;
	}

	bool isLT(int el)
	{
		return info > el;
	}

	bool isGT(int el)
	{
		return info < el;
	}

	bool isEq(int el)
	{
		return info == el;
	}

	void visit() {

	}
};