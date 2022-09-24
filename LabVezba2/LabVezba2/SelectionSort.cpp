#include "SelectionSort.h"

#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;


void selectionSort(int* array, int size) {
    int i, j, imin;

    auto start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

    for (i = 0; i < size - 1; i++) {
        imin = i;   //get index of minimum data
        for (j = i + 1; j < size; j++)
            if (array[j] < array[imin])
                imin = j;
        //placing in correct position
        if (i != imin) {
            int pom = array[i];
            array[i] = array[imin];
            array[imin] = pom;
        }
    }

    auto ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
    cout << "elapsed time: " << ms << "microseconds\n";
}