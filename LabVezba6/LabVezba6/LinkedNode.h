#pragma once
#include <iostream>
using namespace std;

class Edge;

class LinkedNode
{
public:
	int node;
	int val;
	LinkedNode* next;
	Edge* adj;
	LinkedNode* parent;
	LinkedNode  *parent2 ,* child, * prev, * link, *next2;
	int status;
	int degree;

	LinkedNode() { next = NULL; adj = NULL; status = 0; parent = NULL;}
	LinkedNode(int n) { val = n; next = NULL; adj = NULL; status = 0; parent = NULL;}
	LinkedNode(int n, LinkedNode* l) { val = n; next = l; adj = NULL;  status = 0; parent = NULL; }
	LinkedNode(int n, LinkedNode* l, Edge* e) { val = n; next = l; adj = e; status = 0; parent = NULL;}
	void visit() { cout << val << " "; }
};