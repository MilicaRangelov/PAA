#include "FibonacciHeap.h"

FNode* FHeap::Finitialize()
{
    FNode* node = NULL;
    return node;
}

int FHeap::Fib_Link( FNode* node1, FNode* node2)
{
    if (node1 == nullptr || node2 == nullptr) return 0;

    node2->left->right = node2->right;
    node2->right->left = node2->left;
    node2->parent = node1;

    if (node1->child == NULL) {
        node1->child = node2;
        node2->left = node2;
        node2->right = node2;
    }
    else {
        node2->right = node1->child;
        node2->left = node1->child->left;
        node2->left->right = node2;
        node2->right->left = node2;
        node1->child = node2;
    }

    node1->degree++;
    node2->mark = 'F';
    return 0;
}

int FHeap::Fib_Link2(FNode* n1, FNode* n2)
{
    if (n1 == nullptr || n2 == nullptr) return 0;

    n1->left->right = n1->right;
    n1->right->left = n1->left;

    n1->right = n2->right;
    n1->left = n2->left;

    n1->right->left = n1;
    n1->left->right = n1;

    n2->parent = n1;
    if (n1->child == nullptr) {
        n2->left = n2;
        n2->right = n2;
        n1->child = n2;
    }
    else {
        n2->left = n1->child->left;
        n2->right = n1->child;
        n2->left->right = n2;
        n2->right->left = n2;
        n1->child = n2;
    }
    n1->degree++;
    return 0;
}

FNode* FHeap::newFNode(int key)
{
    FNode* node = new FNode;
    node->data = key;
    node->child = node->parent = NULL;
    node->right = node->left = node;
    node->mark = 'F';
    node->c = 'N';
    node->degree = 0;
    return node;
}

FNode* FHeap::insert(FNode* node)
{

    if (head == NULL) {
        head = node;
    }
    else {
        head->left->right = node;
        node->right = head;
        node->left = head->left;
        head->left = node;

        if (node->data < head->data) {
            head = node;
        }
    }
    n++;
    return head;
}

FNode* FHeap::Union(FNode* node1, FNode* node2)
{
    FNode* h = node1;

    if (node1 == NULL)
        return node2;
    if (node2 == NULL)
        return node1;

    node1->right->left = node2->left;
    node2->left->right = node1->right;
    node1->right = node2;
    node2->left = node1;

    return h;
}

FNode* FHeap::extractMin()
{
    FNode* ptr;
    FNode* z = head;

    ptr = head->right;
    if (z == NULL)
        return z;
    FNode* x;
    head->left->right = head->right;
    head->right->left = head->left;
    if (ptr == head) {
        head = NULL;
    }

    if (z->child != NULL) {
        x = z->child;
        while (x->parent != NULL) {
            x->parent = NULL;
            x = x->right;
        }
        if (head == NULL) {
            ptr = x;
        }
        else{
           Union(ptr, x);
        }
        
    }

    z->child = NULL;
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;
    n--;
    head = ptr;
    consolidate(ptr);
    return z;
}

int FHeap::consolidate(FNode* node)
{
    int d, i;
    int D = log2(n) + 1;
    D *= 2;
    FNode** A = new FNode*[D];
    for (i = 0; i <= D; i++)
        A[i] = NULL;

    if (node == NULL)
        return 0;
  
    bool done = false;
    while (!done) {
        int st = node->degree;
        if (A[st] == nullptr) {
            A[st] = node;
            node = node->right;
        }
        else if (A[node->degree] != node) {
            if (A[st]->data < node->data) {
                Fib_Link2(A[st], node);
                node = A[st];
            }
            else {
                Fib_Link(node, A[node->degree]);
            }
            A[st] = nullptr;
        }
        else {
            done = true;
        }
    }

    FNode* poc = node;
    head = node;
    do {
        if (node->data < head->data)
            head = node;
        node = node->right;
    } while (node != poc);

    return 0;
}

int FHeap::display(FNode* node)
{

    FNode* pom = node;
    if (pom == NULL) {
        cout << "Heap empty" << endl;
        return 0;
    }

    do {
        cout << pom->data;
        pom = pom->right;
        if (pom != node) {
            cout << "-->";
        }
    } while (pom != node && pom->right != NULL);

    cout << endl;
    return 0;
}

FNode* FHeap::Find(FNode* node, int key)
{
    if (node == NULL)
        return node;

    FNode* x = node;
    x->c = 'Y';
    FNode* pom = NULL;
    if (x->data == key) {
        pom = x;
        x->c = 'N';
        return pom;
    }

    if (x->child != NULL && pom == NULL) {
        pom = Find(x->child, key);
    }
    if (x->right->c != 'Y' && pom == NULL)
        pom = Find(x->right, key);
   
    x->c = 'N';
    return pom;
  
}



int FHeap::decreaseKey(FNode* node, int key, int value)
{
    FNode* y;
    if (node == NULL)
        return 0;

    FNode* ptr = Find(node, key);

   
    if (ptr == NULL) {
        return 1;
    }

    if (ptr->data < value)
        return 0;

    ptr->data = value;
    y = ptr->parent;

    if (y != NULL && ptr->data < y->data) {
        cut(node, ptr, y);
        cascaseCut(node, y);
    }

    if (ptr->data < head->data)
        head = ptr;
    return 0;
}

int FHeap::deleteKey(FNode* node, int key)
{
    FNode* np = NULL;
    int t;
    t = decreaseKey(node, key, -500000);
    if (!t)
        np = extractMin();
    
    return 0;
}

int FHeap::cut(FNode* node1, FNode* node2, FNode* node3)
{
    if (node2 == node2->right)
        node3->child = NULL;
    node2->left->right = node2->right;
    node2->right->left = node2->left;

    if (node2 == node3->child)
        node3->child = node2->right;
    node3->degree--;

    node2->right = node2;
    node2->left = node2;

    node1->left->right = node2;
    node2->left = node1->left;
    node2->right = node1;
    node1->left = node2;
    node2->parent = NULL;
    node2->mark = 'F';
    return 0;
}

int FHeap::cascaseCut(FNode* node1, FNode* node2)
{
    FNode* pom = node2->parent;
    if (pom != NULL) {
        if (node2->mark == 'F') {
            node2->mark == 'T';
        }
        else {
            cut(node1, node2, pom);
            cascaseCut(node1, pom);
        }
    }
    return 0;
}
