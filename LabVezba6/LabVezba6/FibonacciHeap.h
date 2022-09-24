#pragma once
#include "LinkedNode.h"
#include <cmath>
#include <iostream>
using namespace std;

class FibonacciHeap
{
    
public:
    int size;
    LinkedNode* min;
    FibonacciHeap() {
        min = nullptr;
        size = 0;
    }
    ~FibonacciHeap() {
        if (min != nullptr) delete min;
    }
    void insert(LinkedNode* node);
    void link(LinkedNode* n1, LinkedNode* n2, bool zameni);
    LinkedNode* consolidateTree(LinkedNode* node);
    LinkedNode* findMin(LinkedNode* node);
    LinkedNode* unija(LinkedNode* n1, LinkedNode* n2);  // ne menja parente ni jednog ni drugog
    void setParent(LinkedNode* child, LinkedNode* parent);
    LinkedNode* extractMin();
    LinkedNode* pretrazi(int key, LinkedNode* node);  // nullptr da bi proslo celo stablo
    void setKey(int key, int vrednost);
    void setKey(LinkedNode* node, int vrednost);
    void brisiNode(int key);
};

