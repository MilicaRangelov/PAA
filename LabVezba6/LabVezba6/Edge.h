#pragma once
#include <iostream>
using namespace std;

class LinkedNode;

class Edge
{
public:
	LinkedNode* dest;
	Edge* link;
	int weight;

	Edge()
	{

	}
	Edge(int w, LinkedNode* s)
	{
		weight = w;
		dest = s;
		link = NULL;
	}

	Edge(int w, LinkedNode* s, Edge* l)
	{
		weight = w;
		dest = s;
		link = l;
	}
};

