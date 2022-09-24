#pragma once
#include "Edge.h"
#include "LinkedNode.h"

class GraphAsList
{
public:
	LinkedNode* start;
	int nodeNum;
public:
	GraphAsList()
	{
		start = NULL;
		nodeNum = 0;
	}

	~GraphAsList();
	LinkedNode* findNode(int node);
	Edge* findEdge(int n1, int n2);
	bool insertNode(int n);
	bool deleteNode(int n);
	bool insertEdge(int a, int b);
	bool insertEdge(int weight,int a, int b);
	bool deleteEdge(int a, int b);
	void print();
};

