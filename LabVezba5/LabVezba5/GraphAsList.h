#pragma once
#include "Edge.h"
#include "LinkedNode.h"

class GraphAsList
{
private:
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
	bool insertNode(LinkedNode* node);
	bool insertNode(int n);
	bool deleteNode(int n);
	bool insertEdge(int a, int b, int weight);
	bool insertEdge(LinkedNode* node1, LinkedNode* node2, int weight);
	int edgeCost(int a, int b);
	bool deleteEdge(int a, int b);
	bool isEmpty() { return start == NULL; }
	int size() { return nodeNum; }
	LinkedNode* getStart() { return start; }
	void print();
};

