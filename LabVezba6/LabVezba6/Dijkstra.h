#pragma once
#include "FibonacciHeap.h"
#include "GraphAsList.h"

class Dijkstra
{
public:
	GraphAsList* graph;
	FibonacciHeap* heap;

	Dijkstra() {
		graph = new GraphAsList();
		heap = new FibonacciHeap();
	}

	void DijkstraAlg();
};

