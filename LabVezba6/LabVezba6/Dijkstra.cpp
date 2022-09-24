#include "Dijkstra.h"

void Dijkstra::DijkstraAlg()
{
	LinkedNode* node = graph->start->next;
	while (node != NULL) {
		node->node = INT_MAX;
		node->parent = NULL;
		node = node->next;
	}
	graph->start->node = 0;

	node = graph->start;

	while (node != NULL) {
		heap->insert(node);
		node->status = 1;
		node = node->next;
	}
	while (heap->min !=	NULL) {
		LinkedNode* min = heap->extractMin();
		if (min->node == INT_MAX)
			break;
		Edge* edg = min->adj;
		while (edg != NULL) {
			int alt = min->node + edg->weight;

			if (alt < edg->dest->node) {
				if (edg->dest->status != 0) {
					heap->setKey(edg->dest, alt);
					edg->dest->parent = node;
				}
			}
			edg = edg->link;
		}
	}

	node = graph->start;
	while (node != NULL) {
		cout << "Value of node: " << node->val << " || ";
		cout << "Distance from source: " << node->node << endl;
		node = node->next;
	}
}
