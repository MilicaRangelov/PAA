#pragma once
#include <iostream>
#include <list>
using namespace std;

struct BNode {

	int data, degree;
	BNode* parant, * child, * sibling;
};

class BHeap {

private:
	BNode* head;
	BNode* hr;
	int count;

public:
	BNode* getHead() {
		return head;
	}
	BNode* Initialize();
	BNode* newNode(int data);
	int Link(BNode* head1, BNode* head2);
	BNode* unionBinomialHeap(BNode* head1, BNode* head2);
	BNode* insert(BNode* node);
	BNode* heapStabilization(BNode* node);

	BNode* extraxtMin();
	int Delete(BNode* node, int key);
	int Display(BNode* node);
	BNode* Search(BNode*, int);
	BNode* Decrease_key(BNode* node, int i, int k);

	BHeap() {
		head = Initialize();
		hr = Initialize();
		count = 1;
	}

};










