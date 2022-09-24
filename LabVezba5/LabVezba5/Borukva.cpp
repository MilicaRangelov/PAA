#include "Borukva.h"



void Borukva::addEdge(Edge* edg)
{
	this->graphEdge.at(edg->src->node).push_back(edg);

	if (edg->src != edg->dest) {
		graphEdge.at(edg->dest->node).push_back(edg);
	}
}

int Borukva::find(State** subsets, int i)
{

	if (subsets[i]->parent != i) {
		subsets[i]->parent = this->find(subsets, subsets[i]->parent);
	}

	return subsets[i]->parent;
	
}

void Borukva::findUnion(State** subsets, int x, int y)
{
    int a = this->find(subsets, x);
    int b = this->find(subsets, y);
    if (subsets[a]->rank < subsets[b]->rank)
    {
        subsets[a]->parent = b;
    }
    else if (subsets[a]->rank > subsets[b]->rank)
    {
        subsets[b]->parent = a;
    }
    else
    {
        subsets[b]->parent = a;
        subsets[a]->rank++;
    }
}

void Borukva::boruvka()
{

    int result = 0;
    int selector = graph->size() - 1;
    State** subsets = new State * [graph->size()];
    Edge** cheapest = new Edge * [graph->size()];
    for (int v = 0; v < graph->size(); ++v)
    {
        subsets[v] = new State(v, 0);
    }

    while (selector > 1) {
        for (int v = 0; v < graph->size(); ++v)
        {
            cheapest[v] = NULL;
        }

        for (int v = 0; v < graph->size(); v++) {
            for (int i = 0; i < graphEdge.at(v).size(); i++) {
                int set1 = find(subsets, graphEdge.at(v).at(i)->src->node);
                int set2 = find(subsets, graphEdge.at(v).at(i)->dest->node);

                if (set1 != set2) {

                    if (cheapest[v] == NULL) {
                        cheapest[v] = graphEdge.at(v).at(i);
                    }
                    else if (cheapest[v]->weight > graphEdge.at(v).at(i)->weight) {
                        cheapest[v] = graphEdge.at(v).at(i);
                    }

                }
            }
        }

        for (int i = 0; i < graph->size(); i++) {
            if (cheapest[i] != NULL) {
                int set1 = this->find(subsets, cheapest[i]->src->node);
                int set2 = this->find(subsets, cheapest[i]->dest->node);

                if (set1 != set2) {

                    selector--;
                    findUnion(subsets, set1, set2);
                   /* cout << "\n Include Edge ("
                        << cheapest[i]->src->node
                        << " - "
                        << cheapest[i]->dest->node
                        << ") weight "
                        << cheapest[i]->weight;
                    // Add weight
                    result += cheapest[i]->weight;*/
                }
            }
           // cout << "\n Calculated total weight of MST is "
             //   << result << endl;
        }
    }
}

void Borukva::print()
{
    cout << "\n Graph Adjacency List ";
    for (int i = 0; i < graph->size(); ++i)
    {
        cout << " \n [" << i << "] :";
        // iterate edges of i node
        for (int j = 0; j < this->graphEdge.at(i).size(); ++j)
        {
            cout << "  " << this->graphEdge.at(i).at(j)->dest;
        }
    }
}
