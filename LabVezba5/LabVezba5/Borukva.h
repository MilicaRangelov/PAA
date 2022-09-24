#pragma once
#include "GraphAsList.h"
#include <vector>

class  State
{
public:
	int parent;
	int rank;

	State(int p, int r) {
		parent = p;
		rank = r;
	}

};


class Borukva
{
public:

	GraphAsList* graph = new GraphAsList();
	vector<vector<Edge*>> graphEdge;

	Borukva() {

	}

	void Initialize() {
		for (int i = 0; i < graph->size(); ++i)
		{
			this->graphEdge.push_back(vector < Edge*>());
		}
	}
	void addEdge(Edge* edg);
	int find(State** subsets, int i);
	void findUnion(State** subsets, int x, int y);
	
	void boruvka();
	void print();
};

