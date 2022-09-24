#pragma once
#include "GraphAsList.h"
#include "BinomialHeap.h"
#include <map>

class Prim
{

public:
	GraphAsList* graph = new GraphAsList();
	BHeap* heap = new BHeap();
	map<LinkedNode*, int>* entries = new map<LinkedNode*, int>();

	void createGraph(int* array, int n);
	void addEdges(int a, int b);
	GraphAsList* mst();
	LinkedNode* minCostEndPoint(LinkedNode* node, GraphAsList* result);
	void outGoingEdges(LinkedNode* node, GraphAsList* result);
};

