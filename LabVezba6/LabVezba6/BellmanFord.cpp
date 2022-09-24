#include "BellmanFord.h"

void BellmanFord::inserNodes(int n)
{

}

void BellmanFord::insertEdges(int* array1, int num)
{
}

void BellmanFord::BellmanFordAlg()
{

	LinkedNode* node = graph->start->next;
	while (node != NULL) {
		node->node = INT_MAX;
		node = node->next;
	}
	graph->start->node = 0;

	node = graph->start;
	while (node != NULL) {

		Edge* edg = node->adj;
		while (edg != NULL) {
			if (node->node != INT_MAX && (node->node + edg->weight) < edg->dest->node) {
				edg->dest->node = node->node + edg->weight;
				edg->dest->parent = node;
			}
			edg = edg->link;
		}

		node = node->next;
	}

	node = graph->start;

	while (node != NULL) {

		Edge* edg = node->adj;
		while (edg != NULL){

			if (node->node != INT_MAX && (node->node + edg->weight) < edg->dest->node) {
				cout << "Graph contains negative weight cycle" << endl;
				return;
			}

			edg = edg->link;
		}

		node = node->next;

		node = graph->start;
		while (node != NULL) {
			cout << "Value of node: " << node->val << " || ";
			cout << "Distance from source: " << node->node << endl;
			node = node->next;
		}
	}

}
