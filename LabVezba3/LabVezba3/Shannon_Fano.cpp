#include "Shannon_Fano.h"
#include "BNode.h"
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;
#define MAX_TREE_HT 50
#define brKaraktera 52

char* nizKaraktera() {
	char* niz = new char[brKaraktera];

	for (int i = 0; i < brKaraktera / 2; i++) {
		niz[i] = 'a' + i;
	}

	for (int i = brKaraktera / 2; i < brKaraktera; i++) {
		niz[i] = 'A' + (i - brKaraktera / 2);
	}

	return niz;
}

void identifikujRazliciteSimbole(int* niz, char* simboli, int n) {

	int brRazlicitih = 0;

	auto start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

	char* karakteri = nizKaraktera();

	for (int i = 0; i < n; i++) {

		

		if (simboli[i] >= 'a' && simboli[i] <= 'z') {
			if (niz[(simboli[i] - 'a')] == 0)
				brRazlicitih++;

			niz[(simboli[i] - 'a')]++;
			
		}
		else {
			if (niz[(simboli[i] - 'A' + 26)] == 0)
				brRazlicitih++;
			niz[(simboli[i] - 'A') + 26]++;
		}
	}

	sortiraj(niz, karakteri);

	int* frekvencija = new int[brRazlicitih];
	char* karakteri2 = new char[brRazlicitih];

	for (int i = 0; i < brRazlicitih; i++) {
		frekvencija[i] = niz[i];
		karakteri2[i] = karakteri[i];
	}

	delete[] niz;
	delete[] karakteri;

	niz = frekvencija;
	karakteri = karakteri2;

	int poc, kraj;
	nadjiPozicije(&poc, &kraj, niz, brRazlicitih);
	
	BTree* tree = kreirajStablo(&poc, &kraj, niz, karakteri, brRazlicitih);
	
	auto ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "elapsed time: " << ms << "microseconds\n";

	int arr[MAX_TREE_HT], top = 0;
	printCodes(tree->root, arr, top);

}

void nadjiPozicije(int* poc, int* kraj, int* niz, int n) {
	
	(*poc) = 0;
	(*kraj) = 1;

	int deo1 = niz[0];
	int deo2 = 0;
	for (int i = 1; i < n; i++) {
		deo2 += niz[i];
	}
	int minDiff = abs(deo1-deo2);
	

	for (int i = 1; i < n - 1; i++) {

		deo1 += niz[i];
		deo2 -= niz[i];
		if (abs(deo1 - deo2) < minDiff) {

			minDiff = abs(deo1 - deo2);
			(*kraj) = i + 1;
		}
	}
	
}


void sortiraj(int* niz1, char* niz2) {

	int i, j;
	int imax;
	for (i = 0; i < brKaraktera - 1; i++) {
		imax = i;
		for (j = i + 1; j < brKaraktera; j++)
			if (niz1[j] > niz1[imax])
				imax = j;
		
		if (i != imax) {
			int pom = niz1[i];
			niz1[i] = niz1[imax];
			niz1[imax] = pom;

			char pom2 = niz2[i];
			niz2[i] = niz2[imax];
			niz2[imax] = pom2;
		}
	}
}

BTree* kreirajStablo(int* poc, int* kraj, int* niz, char* karakteri, int n) {

	BTree* tree = new BTree();
	BNode* left = NULL;
	BNode* right = NULL;

	tree->root = new BNode(); //bez vrednosti

	if (n == 2) {
		tree->root->left = new BNode(karakteri[(*poc)]);
		tree->root->right = new BNode(karakteri[(*kraj)], 1);
		return tree;
	}

	tree->root->left = new BNode(); // bez vrednosti
	tree->root->right = new BNode();
	tree->root->right->weight = 1;
	//Levo podstablo
	
	left = tree->root->left;
	if (abs((*poc) - (*kraj)) == 1) {
		left->left = new BNode(niz[(*poc)]);
	}
	else {
		for (int i = (*poc); i < (*kraj) - 1; i++) {

			left->left = new BNode(karakteri[i]);

			if ((i + 1) == ((*kraj) - 1)) {
				left->right = new BNode(karakteri[i + 1], 1);
			}
			else {
				left->right = new BNode(1);
				left = left->right;
			}
		}
	}

	//desno podstablo

	right = tree->root->right;
	if (abs((n) - (*kraj)) == 1) {
		right->left = new BNode(niz[(*kraj)]);
	}
	else {
		for (int i = (*kraj); i < n - 1; i++) {

			right->left = new BNode(karakteri[i]);

			if ((i + 1) == (n - 1)) {
				right->right = new BNode(karakteri[i + 1], 1);
			}
			else {
				right->right = new BNode(1);
				right = right->right;
			}
		}
	}

	
	return tree;
}
void printCodes(BNode* root, int* arr, int top) {

	if (root->left) {
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}

	if (root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
	if (root->left == NULL && root->right == NULL) {
		cout << root->info << "  | ";
		printSFArray(arr, top);
	}

}
void printSFArray(int arr[], int n) {
	int i;
	for (i = 0; i < n; ++i)
		cout << arr[i];

	cout << "\n";
}