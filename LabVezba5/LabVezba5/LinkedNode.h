#pragma once
#include <iostream>
using namespace std;

class Edge;

class LinkedNode
{
public:
	int node;
	int value;
	LinkedNode* next;
	Edge* adj;
	LinkedNode* prev;
	LinkedNode* parent;

	int status;

	LinkedNode() { next = NULL; adj = NULL; status = 0; value = INT_MAX;  parent = this; }
	LinkedNode(int n) { node = n; next = NULL; adj = NULL; status = 0; value = INT_MAX;  parent = this;}
	LinkedNode(int n, LinkedNode* l) { node = n; next = l; adj = NULL;  status = 0; value = INT_MAX;  parent = this;}
	LinkedNode(int n, LinkedNode* l, Edge* e) { node = n; next = l; adj = e; status = 0; value = INT_MAX;  parent = this; }
	void visit() { cout << node << " "; }
};

