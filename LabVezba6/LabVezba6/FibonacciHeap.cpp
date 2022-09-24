#include "FibonacciHeap.h"

void FibonacciHeap::insert(LinkedNode* node)
{
    if (min == nullptr) {
        min = node;
        min->next2 = min;
        min->prev = min;
    }
    else {
        LinkedNode* minprev = min->prev;
        minprev->next2 = node;
        node->next2 = min;
        min->prev = node;
        node->prev = minprev;
        if (node->node < min->node) min = node;
    }
    node->parent2 = nullptr;
    size++;

}

void FibonacciHeap::link(LinkedNode* n1, LinkedNode* n2, bool zameni)
{
    if (n1 == nullptr || n2 == nullptr) return;

    /**
    n1->print(n1);
    cout << '\n';
    n2->print(n2);
    cout << '\n';
    /**/
    if (!(n1->next2 == n2 || n1->prev == n2 || n2->next2 == n1 ||
        n2->prev == n1) &&
        zameni) {
        LinkedNode* n1prev = n1->prev;
        LinkedNode* n1next2 = n1->next2;

        LinkedNode* n2prev = n2->prev;
        LinkedNode* n2next2 = n2->next2;

        n1prev->next2 = n2;
        n1next2->prev = n2;

        n2->prev = n1prev;
        n2->next2 = n1next2;

        n2prev->next2 = n1;
        n2next2->prev = n1;

        n1->next2 = n2next2;
        n1->prev = n2prev;
    }

    n2->prev->next2 = n2->next2;
    n2->next2->prev = n2->prev;
    n2->parent2 = n1;
    if (n1->child == nullptr) {
        n2->prev = n2;
        n2->next2 = n2;
    }
    else {
        n2->next2 = n1->child->next2;
        n2->prev = n1->child;
        n2->next2->prev = n2;
        n2->prev->next2 = n2;
    }
    n1->child = n2;
    n1->degree++;
}

LinkedNode* FibonacciHeap::consolidateTree(LinkedNode* node)
{
    if (node == nullptr) return nullptr;
    int vel = (int)log2(size) + 1;
    vel *= 2;
    LinkedNode** degree = new LinkedNode * [vel];

    for (int i = 0; i < vel; i++) degree[i] = nullptr;

    node = min;
    if (node == nullptr) {
        return nullptr;
    }
    bool done = false;
    int st = node->degree;
    while (!done) {
        st = node->degree;
        if (degree[st] == nullptr) {
            degree[st] = node;
            node = node->next2;
        }
        else if (degree[node->degree] != node) {
            if (degree[st]->node < node->node) {
                link(degree[st], node, true);
                node = degree[st];
            }
            else {
                link(node, degree[st], false);
            }
            degree[st] = nullptr;
        }
        else if (node == degree[st]) {
            done = true;
        }
    }
    min = node;
    return findMin(node);
}

LinkedNode* FibonacciHeap::findMin(LinkedNode* node)
{
    if (node == nullptr) return nullptr;
    LinkedNode* st = node;
    int mink = node->node;
    while (node->next2 != st) {
        if (node->next2->node < mink) {
            min = node->next2;
            mink = min->node;
        }
        node = node->next2;
    }
   
    return min;
}

LinkedNode* FibonacciHeap::unija(LinkedNode* n1, LinkedNode* n2)
{
    if (n1 == nullptr) return n2;
    if (n2 == nullptr) return n1;

    n1->next2->prev = n2->prev;
    
    n2->prev->next2 = n1->next2;

    n1->next2 = n2;
    n2->prev = n1;
    return n1;
}

void FibonacciHeap::setParent(LinkedNode* child, LinkedNode* parent2)
{
    while (child->parent2 != parent2) {
        child->parent2 = parent2;
        child = child->next2;
    }
}

LinkedNode* FibonacciHeap::extractMin()
{
    if (min == nullptr) return nullptr;
    if (min->next2 == min) {
        LinkedNode* m = min;
        if (min->child != nullptr) min->child->parent2 = nullptr;
        min = min->child;
        m->next2 = nullptr;
        m->prev = nullptr;
        m->child = nullptr;
        findMin(min);
        size--;
        return m;
    }
    LinkedNode* prev = min->prev;
    LinkedNode* next2 = min->next2;

    prev->next2 = next2;
    next2->prev = prev;
    min->prev = nullptr;
    min->next2 = nullptr;
    LinkedNode* ret = min;
    min = next2;

    if (ret->child != nullptr) {
        LinkedNode* child = ret->child;
        child->parent2 = nullptr;
        min = unija(min, child);
    }
    consolidateTree(min);
    size--;
    return ret;
}

LinkedNode* FibonacciHeap::pretrazi(int key, LinkedNode* node)
{
    LinkedNode* ret = nullptr;
    if (node == nullptr && min->node != key)
        node = min->next2;
    else if (min->node == key)
        return min;

    while (ret != nullptr && node != min) {
        if (node->node < key && node->child != nullptr)
            ret = pretrazi(key, node->child);
        node = node->next2;
    }
    return ret;
}

void FibonacciHeap::setKey(int key, int vrednost)
{
    LinkedNode* node = pretrazi(key, nullptr);
    if (node == nullptr) return;  // NIJE NASLO ELEMENT
    node->node = vrednost;
    while (node->parent2 != nullptr && node->parent2->node > node->node) {
        key = node->parent2->node;
        node->parent2->node = node->node;
        node->node = key;
        node = node->parent2;
    }
    
}

void FibonacciHeap::setKey(LinkedNode* node, int vrednost)
{
    if (node == nullptr) return;  // NO
    if (node->next2 == nullptr) {
        node->next2 = node;
        node->prev = node;
    }
    if (node->parent2 != nullptr) {
        node->parent2->child = nullptr;
        node->parent2->degree = 0;
        setParent(node, nullptr);
    }
    node->node = vrednost;
    findMin(unija(min, node));
}

void FibonacciHeap::brisiNode(int key)
{
    size--;
    LinkedNode* node = pretrazi(key, nullptr);
    if (node == nullptr) return;  // NIJE NASLO CVOR!
    LinkedNode* child = node->child;
    setParent(child, nullptr);
    unija(child, min);
    node->prev->next2 = node->next2;
    node->next2->prev = node->prev;
    if (node == min) findMin(node->next2);
    node->prev = nullptr;
    node->next2 = nullptr;
    node->child = nullptr;
    delete node;
}
