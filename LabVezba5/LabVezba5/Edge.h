#pragma once
#include <iostream>
using namespace std;

class LinkedNode;

class Edge
{

public:
	LinkedNode* src;
	LinkedNode* dest;
	Edge* link;
	int weight;

	Edge()
	{

	}
	Edge(int w, LinkedNode* s)
	{
		src = NULL;
		weight = w;
		dest = s;
		link = NULL;
	}

	Edge(int w, LinkedNode* s, Edge* l)
	{
		src = NULL;
		weight = w;
		dest = s;
		link = l;
	}

	Edge(LinkedNode* ss,int w, LinkedNode* s, Edge* l)
	{
		src = ss;
		weight = w;
		dest = s;
		link = l;
	}
};

