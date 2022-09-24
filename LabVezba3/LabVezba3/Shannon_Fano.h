#pragma once
#include "BTree.h"

char* nizKaraktera();
void identifikujRazliciteSimbole(int* niz, char* simboli, int n);
void sortiraj(int* niz1, char* niz2);
void nadjiPozicije(int *poc, int *kraj, int* niz, int n);
BTree* kreirajStablo(int* poc, int* kraj, int* niz, char* karakteri, int n);
void printCodes(BNode* root, int* arr, int top);
void printSFArray(int arr[], int n);