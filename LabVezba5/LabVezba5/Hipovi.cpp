#include "BinomialHeap.h"
#include "FibonacciHeap.h"
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std::chrono;
using namespace std;

void generateArray(int* array1, int* array2, int n) {

	for (int i = 0; i < n; i++) {
		array1[i] = array2[i] = rand() % 10001;
	}

}

int funkcija() {

	//num of elements
	int n;

	n = 100;
	int* array1 = new int[n];
	int* array2 = new int[n];

	generateArray(array1, array2, n);

	for (int i = 0; i < n; i++) {
		cout << array1[i] << " ";
	}
	cout << endl;
	BHeap bh;
	BNode* pom;
	BNode* head = bh.Initialize();

	auto start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	for (int i = 0; i < n; i++) {
		pom = bh.newNode(array1[i]);
		head = bh.insert(pom);
	}
	
	int prec = n * 0.1;

	BNode* pom2 = head;
	cout << "Binomial heap: " << endl;
	bh.Display(head);
	auto ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "elapsed time: " << ms << "microseconds\n";
	
	cout << "Extract min: " << endl;
	start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	for (int i = 0; i < prec; i++) {
		pom2 = bh.extraxtMin();
		head = bh.getHead();
		cout << "Min element: "<< pom2->data << endl;
	}
	ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "elapsed time: " << ms << "microseconds\n";
	bh.Display(head);

	cout << "-----------------------------------------------------" << endl;
	cout << "-----------------------------------------------------" << endl;

	cout << "Decreas key: " << endl;
	start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	for (int i = 0; i < prec; i++) {
		
		bh.Decrease_key(head,array1[rand()%n], rand() % n);
		head = bh.getHead();
	}
	
	ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "elapsed time: " << ms << "microseconds\n";
	bh.Display(head);
	cout << "-----------------------------------------------------" << endl;
	cout << "-----------------------------------------------------" << endl;

	cout << "Delete key: " << endl;
	start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	for (int i = 0; i < prec; i++) {

		bh.Delete(head, array1[rand() % n]);
		head = bh.getHead();
	}

	ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "elapsed time: " << ms << "microseconds\n";
	bh.Display(head);

	cout << "Add key: " << endl;
	start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	for (int i = 0; i < prec; i++) {

		BNode* nov = bh.newNode(rand() % 10001);
		bh.insert(nov);
		head = bh.getHead();
	}
	bh.Display(head);
	ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "elapsed time: " << ms << "microseconds\n";

	cout << "-----------------------------------------------------" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "-----------------------------------------------------" << endl;

	FHeap fh;
	FNode* node;
	FNode* headF = fh.Finitialize();

	start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

	for (int i = 0; i < n; i++) {
		node = fh.newFNode(array2[i]);
		headF = fh.insert(node);

	}
	cout << "Fibbonaci heap: " << endl;
	fh.display(headF);
	ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "elapsed time: " << ms << "microseconds\n";

	cout << "-----------------------------------------------------" << endl;
	cout << "-----------------------------------------------------" << endl;

	cout << "Extract min: " << endl;
	start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	for (int i = 0; i < prec; i++) {

		node = fh.extractMin();
		cout << "Min element: " << node->data << endl;
		headF = fh.getHead();
	}
	fh.display(headF);
	ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "elapsed time: " << ms << "microseconds\n";

	cout << "Decrease key: " << endl;
	start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	for (int i = 0; i < prec; i++) {
		fh.decreaseKey(headF, array2[rand() % n], rand() % n);
		headF = fh.getHead();
	}
	fh.display(headF);
	ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "elapsed time: " << ms << "microseconds\n";

	cout << "-----------------------------------------------------" << endl;
	cout << "-----------------------------------------------------" << endl;

	cout << "Delete key: " << endl;
	start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	for (int i = 0; i < prec; i++) {
		
		fh.deleteKey(headF, array2[rand() % n]);
		headF = fh.getHead();
	}
	fh.display(headF);
	ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "elapsed time: " << ms << "microseconds\n";

	cout << "-----------------------------------------------------" << endl;
	cout << "-----------------------------------------------------" << endl;

	cout << "Add key: " << endl;
	start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	for (int i = 0; i < prec; i++) {

		FNode* novi = fh.newFNode(rand() % 10001);
		fh.insert(novi);
		headF = fh.getHead();
	}
	fh.display(headF);
	ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "elapsed time: " << ms << "microseconds\n";


	delete[] array1;
	delete[] array2;

	
	return 0;
}