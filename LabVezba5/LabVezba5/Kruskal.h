#pragma once
#include <algorithm>
#include "GraphAsList.h"
#include <vector>
#define edge pair<int,int>
class Kruskal
{
public:
	GraphAsList* graph = new GraphAsList();
	vector<pair <int, edge> > G;
	vector<pair <int, edge> > T;

	Kruskal() {
		G.clear();
		T.clear();
	}
	void AddWeightEdge(int u, int v, int w);
	LinkedNode* findParent(LinkedNode* p);
	void unionSet(LinkedNode* u, LinkedNode* v);
	void kruskal();
	void print();

};

