#pragma once
#include "GraphAsList.h"

class BellmanFord
{
public:
	GraphAsList* graph;
	int edgNum;
	BellmanFord() {
		edgNum = 0;
		graph = new GraphAsList();
	}

	~BellmanFord() {
		delete graph;
	}

	void inserNodes(int n);
	void insertEdges(int* array1, int num);
	void BellmanFordAlg();
};

