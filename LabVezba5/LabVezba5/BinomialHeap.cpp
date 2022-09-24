#include "BinomialHeap.h"

BNode* BHeap::Initialize()
{
	BNode* node = NULL;
	return node;
}

BNode* BHeap::newNode(int data)
{
	BNode* node = new BNode;
	node->data = data;
	node->degree = 0;
	node->parant = node->child = node->sibling = NULL;
	return node;
}

int BHeap::Link(BNode* head1, BNode* head2)
{
	head1->parant = head2;
	head1->sibling= head2->child;
	head2->child = head1;
	head2->degree = head2->degree + 1;

	return 0;
}

BNode* BHeap::unionBinomialHeap(BNode* head1, BNode* head2)
{

	BNode* node = head1;

	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	if (head1->degree > head2->degree) {
		head1 = head2;
		head2 = node;
		node = head1;
	}

	while (head2 != NULL && head1 != NULL) {
		if (head1->sibling == NULL) {
			head1->sibling = head2;
			head2 = NULL;
		}
		else if (head1->sibling->degree > head2->degree) {
			BNode* pom =head2;
			head2 = head2->sibling;
			pom->sibling = head1->sibling;
			head1->sibling = pom;
		}
		else {
			head1 = head1->sibling;
		}
	}

	node = heapStabilization(node);
	return node;
}


BNode* BHeap::insert(BNode* node)
{

	if (this->head == NULL)
		head = node;
	else {
		node->sibling = head;
		head = node;
		head = heapStabilization(head);
	}
	
	return head;
}

BNode* BHeap::heapStabilization(BNode* node)
{
	BNode* prev_x;
	BNode* next_x;
	BNode* x;
	prev_x = NULL;
	x = node;

	next_x = x->sibling;
	while (next_x != NULL) {

		if ((x->degree != next_x->degree) || ((next_x->sibling != NULL) && (next_x->sibling->degree == x->degree))) {

			prev_x = x;
			x = next_x;
		}
		else {
			if (x->data <= next_x->data) {
				x->sibling = next_x->sibling;
				Link(next_x, x);
			}
			else {
				if (prev_x == NULL)
					node = next_x;
				else {
					prev_x->sibling = next_x;

				}
				Link(x, next_x);
				x = next_x;
			}
		}
		next_x = x->sibling;
	}

	return node;
}

BNode* BHeap::extraxtMin()
{
	BNode* temp = NULL;
	BNode* x = head;

	if (x == NULL) {
		//cout << "Nothing to extract" << endl;
		return x;
	}

	int min = x->data;
	BNode* pom = x, *minNode = x, *preMin = NULL;
	while (pom->sibling != NULL) {
		if (pom->sibling->data < min) {
			min = pom->sibling->data;
			preMin = pom;
			minNode= pom->sibling;
		}
		pom = pom->sibling;
	}

	if (minNode == head) {
		head = head->sibling;
	}
	else {
		preMin->sibling = minNode->sibling;
	}

	if (minNode->child != NULL) {
		BNode* pom2 = minNode->child;
		pom2->parant = NULL;
		minNode->child = NULL;

		BNode* un = pom2;
		pom2 = un->sibling;

		un->sibling = NULL;

		while (pom2 != NULL) {
			pom2->parant = NULL;
			BNode* sl = pom2->sibling;
			pom2->sibling = un;
			un = pom2;
			pom2 = sl;
		}
		head = unionBinomialHeap(head, un);
	}

	minNode->parant = NULL;
	minNode->sibling = NULL;
	minNode->child = NULL;

	return minNode;
}

int BHeap::Delete(BNode* node, int key)
{
	BNode* pom;
	if (node == NULL) {
		cout << "Heap empty" << endl;
		return  0;
	}
	Decrease_key(node, key, -1000);
	pom = extraxtMin();

	return 0;
}

int BHeap::Display(BNode* node)
{
	if (node == NULL) {
		cout << "Binomial Heap is empty!" << endl;
		return 0;
	}
	cout << "Root nodes: " << endl;
	BNode* pom = node;
	while (pom != NULL) {
		cout << pom->data;
		if (pom->sibling != NULL) {
			cout << "-->";
		}
		pom = pom->sibling;
	}
	cout << endl;
	return 0;
}

BNode* BHeap::Search(BNode* node, int key)
{

	BNode* x = node;
	BNode* pom = NULL;

	if (x->data == key) {
		pom = x;
		return pom;
	}

	if (x->child != NULL && pom == NULL) {
		pom = Search(x->child, key);
	}
	if (x->sibling != NULL && pom == NULL) {
		pom = Search(x->sibling, key);
	}
		
	return pom;
}



BNode* BHeap::Decrease_key(BNode* node, int i, int k)
{
	int temp;
	BNode* pom;
	BNode* y;
	BNode* z;

	pom = Search(node, i);
	if (pom == NULL) {
		return 0;
	}
	if (k > pom->data)
		return 0;
	pom->data = k;
	y = pom;
	z = pom->parant;

	while (z != NULL && y->data < z->data) {
		temp = y->data;
		y->data = z->data;
		z->data = temp;

		y = z;
		z = z->parant;
	}

	return y;
}

