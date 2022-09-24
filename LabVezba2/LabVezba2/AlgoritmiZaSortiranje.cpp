//SELECTION HEAP RADIX
#include "SelectionSort.h"
#include "HeapSort.h"
#include "RadixSort.h"
#include <iostream>
#include <cmath>
using namespace std;

void generateArray(int* array1, int* array2, int* array3, int n) {

	for (int i = 0; i < n; i++) {
		array2[i] = array3[i] =array1[i] = rand() % 10001;
	}
}

void printArray(int* array, int n) {

	cout << "Array of " << n << " elements: " << endl;
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int main() {

	//num of elements
	int n;

	n = 100;
	int* array1 = new int[n];
	int* array2 = new int[n];
	int* array3 = new int[n];

	generateArray(array1, array2,array3, n);

	cout << "Number of elements: " << n << endl;
	cout << "Array before sorting: " << endl;
	printArray(array1, n);
	
	cout << "Selection sort: " << endl;
	selectionSort(array1, n);
	printArray(array1, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "Heap sort: " << endl;
	heapSort(array2, n);
	printArray(array2, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "Radix sort: " << endl;
	RadixSort(array3, n);
	printArray(array3, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;
	
	delete[] array1;
	delete[] array2;
	delete[] array3;

	n = 1000;

	array1 = new int[n];
	array2 = new int[n];
	array3 = new int[n];
	generateArray(array1, array2, array3, n);

	cout << "Number of elements: " << n << endl;
	cout << "Array before sorting: " << endl;
	printArray(array1, n);

	cout << "Selection sort: " << endl;
	selectionSort(array1, n);
	printArray(array1, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "Heap sort: " << endl;
	heapSort(array2, n);
	printArray(array2, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "Radix sort: " << endl;
	RadixSort(array3, n);
	printArray(array3, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;
	delete[] array1;
	delete[] array2;
	delete[] array3;

	n = 10000;

	array1 = new int[n];
	array2 = new int[n];
	array3 = new int[n];
	generateArray(array1, array2, array3, n);

	cout << "Number of elements: " << n << endl;
	cout << "Array before sorting: " << endl;
	printArray(array1, n);

	cout << "Selection sort: " << endl;
	selectionSort(array1, n);
	printArray(array1, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "Heap sort: " << endl;
	heapSort(array2, n);
	printArray(array2, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "Radix sort: " << endl;
	RadixSort(array3, n);
	printArray(array3, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;
	delete[] array1;
	delete[] array2;
	delete[] array3;

	/*n = 100000;

	array1 = new int[n];
	array2 = new int[n];
	array3 = new int[n];
	generateArray(array1, array2, array3, n);

	cout << "Number of elements: " << n << endl;
	cout << "Array before sorting: " << endl;
	printArray(array1, n);

	cout << "Selection sort: " << endl;
	selectionSort(array1, n);
	printArray(array1, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "Heap sort: " << endl;
	heapSort(array2, n);
	printArray(array2, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "Radix sort: " << endl;
	RadixSort(array3, n);
	printArray(array3, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;
	delete[] array1;
	delete[] array2;
	delete[] array3;


	n = 1000000;

	array1 = new int[n];
	array2 = new int[n];
	array3 = new int[n];
	generateArray(array1, array2, array3, n);

	cout << "Number of elements: " << n << endl;
	cout << "Array before sorting: " << endl;
	printArray(array1, n);

	cout << "Selection sort: " << endl;
	selectionSort(array1, n);
	printArray(array1, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "Heap sort: " << endl;
	heapSort(array2, n);
	printArray(array2, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "Radix sort: " << endl;
	RadixSort(array3, n);
	printArray(array3, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;
	delete[] array1;
	delete[] array2;
	delete[] array3;
	
	n = 10000000;

	array1 = new int[n];
	array2 = new int[n];
	array3 = new int[n];
	generateArray(array1, array2, array3, n);

	cout << "Number of elements: " << n << endl;
	cout << "Array before sorting: " << endl;
	printArray(array1, n);

	cout << "Selection sort: " << endl;
	selectionSort(array1, n);
	printArray(array1, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "Heap sort: " << endl;
	heapSort(array2, n);
	printArray(array2, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;

	cout << "Radix sort: " << endl;
	RadixSort(array3, n);
	printArray(array3, n);
	cout << "----------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------" << endl;
	delete[] array1;
	delete[] array2;
	delete[] array3;
	
	*/



	return 0;
}






