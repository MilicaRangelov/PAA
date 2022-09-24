#include "GraphAsList.h"
GraphAsList::~GraphAsList()
{
	LinkedNode* ptr;
	while (start != NULL)
	{
		ptr = start;
		Edge* prt2 = start->adj, * ptr2;
		while (prt2 != NULL)
		{
			ptr2 = prt2;
			prt2 = prt2->link;
			delete ptr2;
		}
		delete ptr;
		start = start->next;
	}
}

LinkedNode* GraphAsList::findNode(int node)
{
	if (start == NULL)
		throw exception("Nema cvorova");
	LinkedNode* pom = start;
	while (pom != NULL && pom->val != node)
	{
		pom = pom->next;
	}
	return pom;
}

Edge* GraphAsList::findEdge(int n1, int n2)
{
	if (start == NULL)
		throw exception("Nema cvorova");
	LinkedNode* a = findNode(n1);
	if (a == NULL)
		throw exception("Nema potega");
	Edge* pom = a->adj;
	while (pom != NULL && pom->dest->val != n2)
	{
		pom = pom->link;
	}
	return pom;
}

bool GraphAsList::insertNode(int n)
{
	LinkedNode* newNode = new LinkedNode(n, start, NULL);
	if (newNode == NULL) return false;
	start = newNode;
	nodeNum++;

	return true;
}

bool GraphAsList::deleteNode(int n)
{
	LinkedNode* prev = NULL;
	LinkedNode* pom = start;
	Edge* e, * epr;
	while (pom != NULL && pom->val != n)
	{
		epr = NULL;
		e = pom->adj;
		while (e != NULL && e->dest->val != n)
		{
			epr = e;
			e = e->link;
		}
		if (e != NULL)
		{
			if (epr == NULL)
				pom->adj = e->link;
			else
			{
				epr->link = e->link;
			}
			delete e;
		}
		prev = pom;
		pom = pom->next;
	}
	if (pom != NULL)
	{
		Edge* poteg = pom->adj;
		while (pom->adj != NULL)
		{
			poteg = pom->adj;
			pom->adj = pom->adj->link;
			delete poteg;
		}
		if (prev == NULL)
			start = pom->next;
		else
			prev->next = pom->next;
		delete pom;
		if (prev == NULL)
			pom = start;
		else
			pom = prev->next;
	}
	while (pom != NULL)
	{
		epr = NULL;
		e = pom->adj;
		while (e != NULL && e->dest->val != n)
		{
			epr = e;
			e = e->link;
		}
		if (e != NULL)
		{
			if (epr == NULL)
				pom->adj = e->link;
			else
			{
				epr->link = e->link;
			}
			delete e;
		}
		pom = pom->next;
	}
	return true;
}

bool GraphAsList::insertEdge(int a, int b)
{
	LinkedNode* an = findNode(a);
	LinkedNode* bn = findNode(b);
	if (an == NULL || bn == NULL)
		return false;
	an->adj = new Edge(1, bn, an->adj);
	return true;

	return false;
}

bool GraphAsList::insertEdge(int weight,int a, int b)
{
	LinkedNode* an = findNode(a);
	LinkedNode* bn = findNode(b);
	if (an == NULL || bn == NULL)
		return false;
	an->adj = new Edge(weight, bn, an->adj);
	return true;

	return false;
}

bool GraphAsList::deleteEdge(int a, int b)
{
	LinkedNode* n1 = findNode(a);
	if (n1 == NULL)
		return false;
	Edge* prev = NULL;
	Edge* pom = n1->adj;
	while (pom != NULL && pom->dest->val != b)
	{
		prev = pom;
		pom = pom->link;
	}

	if (pom == NULL)
		return false;
	if (prev == NULL)
	{
		n1->adj = pom->link;
	}
	else
	{
		prev->link = pom->link;
	}
	delete pom;
	return true;
}

void GraphAsList::print()
{
	LinkedNode* pom = start;
	while (pom != NULL)
	{
		pom->visit();
		Edge* edg = pom->adj;
		while (edg != NULL)
		{
			edg->dest->visit();
			edg = edg->link;
		}
		cout << endl;
		pom = pom->next;

	}

}