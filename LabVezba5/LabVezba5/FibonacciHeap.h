#pragma once
#include <iostream>
using namespace std;

struct FNode {
	int data;
	int degree;
	FNode* parent;
	FNode* child;
	FNode* left;
	FNode* right;
	char mark;
	char c;
};

class FHeap {

private: 
	int n;
	FNode* head;

public:
	FNode* getHead() {
		return head;
	}
	FNode* Finitialize();
	int Fib_Link(FNode* node2, FNode* node3);
	int Fib_Link2(FNode* node1, FNode* node2);
	FNode* newFNode(int key);
	FNode* insert(FNode* node);
	FNode* Union(FNode* node1, FNode* node2);
	FNode* extractMin();
	int consolidate(FNode* node);
	int display(FNode* node);
	FNode* Find(FNode* node, int key);
	int decreaseKey(FNode* node, int key, int value);
	int deleteKey(FNode* node, int key);
	int cut(FNode* node1, FNode* node2, FNode* node3);
	int cascaseCut(FNode* node1, FNode* node2);

	FHeap() {
		head = Finitialize();
		n = 0;
	}
};