#include "Prim.h"

void Prim::createGraph(int* array, int n)
{
}

void Prim::addEdges(int a, int b)
{
}

GraphAsList* Prim::mst()
{
    GraphAsList* result = new GraphAsList();
    if (graph->isEmpty())
        return result;
    LinkedNode* startNode = graph->getStart();
    result->insertNode(startNode->node);

    outGoingEdges(startNode, result);
  
    for (int i = 0; i < graph->size() - 1; i++) {
        BNode* node = heap->extraxtMin();
        map<LinkedNode*, int>::iterator it;
        LinkedNode* toAdd = NULL;
        if (node != NULL) {
            for (it = entries->begin(); it != entries->end(); it++)
            {
                if (it->second == node->data) {
                    toAdd = it->first;
                    break;
                }

            }
        }
        if (toAdd != NULL) {
            LinkedNode* endpoint = minCostEndPoint(toAdd, result);

            result->insertNode(toAdd->node);
            int val = graph->edgeCost(toAdd->node, endpoint->node);
            result->insertEdge(toAdd->node, endpoint->node, val);

            outGoingEdges(toAdd, result);
        }
    }


    return result;
}

LinkedNode* Prim::minCostEndPoint(LinkedNode* node, GraphAsList* result)
{
    LinkedNode* endPoint = NULL;
    int leasCost = INT_MAX;
    Edge* edg = node->adj;
    while (edg != NULL) {
        if (!result->findNode(edg->dest->node)) { 
            edg = edg->link;
            continue; 
        }

        if (edg->weight >= leasCost) {
            edg = edg->link;
            continue;
        }

        endPoint = edg->dest;
        leasCost = edg->weight;
        edg = edg->link;
    }
    return endPoint;
}

void Prim::outGoingEdges(LinkedNode* node,GraphAsList* result)
{
    Edge* edg = node->adj;

    while (edg != NULL) {
        if (result->findNode(edg->dest->node)) {
            edg = edg->link;
            continue;
        }

        if (entries->find(edg->dest) == entries->end()) {
            BNode* pom = heap->newNode(edg->weight);
             heap->insert(pom);
             entries->insert({ edg->dest,pom->data });
        }
        else {
            map<LinkedNode*,int>::iterator it;
            for (it = entries->begin(); it != entries->end(); it++)
            {
                if (it->first->node == edg->dest->node) {
                    if (it->second > edg->weight) {
                       BNode* fn = heap->Decrease_key(heap->getHead(), it->second,edg->weight);
                       it->second = edg->weight;
                    }
                    break;
                }

            }
        }
        edg = edg->link;
    }

}
