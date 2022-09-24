#include "RadixSort.h"
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;

int getMax(int* array, int n) {

    int max = array[0];
    for (int i = 1; i < n; i++) {

        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

void countSort(int* array, int n, int exp) {

    int* output = new int[n];
    int c[10] = { 0 };
    int i;

    for (i = 0; i < n; i++) {
        c[(array[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        c[i] = c[i - 1] + c[i];
    }

    for (i = n - 1; i >= 0; i--) {
        output[c[(array[i] / exp) % 10] - 1] = array[i];
        c[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        array[i] = output[i];

}

void RadixSort(int* array, int n) {

    auto start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

    int m = getMax(array, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(array, n, exp);
    }

    auto ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
    cout << "elapsed time: " << ms << "microseconds\n";
}