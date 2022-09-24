#include "HeapSort.h"
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;


void Heapify(int* array, int n, int i) {

    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && array[l] > array[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && array[r] > array[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        int pom = array[i];
        array[i] = array[largest];
        array[largest] = pom;

        // Recursively heapify the affected sub-tree
        Heapify(array, n, largest);
    }
}

void buildHeap(int* array, int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(array, n, i);

}

void heapSort(int* array, int n) {

    auto start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  
    buildHeap(array, n);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int pom = array[0];
        array[0] = array[i];
        array[i] = pom;

        // call max heapify on the reduced heap
        Heapify(array, i, 0);
    }

    auto ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
    cout << "elapsed time: " << ms << "microseconds\n";
}