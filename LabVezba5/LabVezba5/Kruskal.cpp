#include "Kruskal.h"

void Kruskal::AddWeightEdge(int u, int v, int w)
{
    G.push_back(make_pair(w, edge(u, v)));
}

LinkedNode* Kruskal::findParent(LinkedNode* p)
{
    if (p->parent == p) {
        return p;
    }
    return findParent(p->parent);
}

void Kruskal::unionSet(LinkedNode* u, LinkedNode* v)
{
    u->parent = v->parent;
}

void Kruskal::kruskal()
{
    LinkedNode* uP = NULL;
    LinkedNode* vP = NULL;
    sort(G.begin(), G.end());

    for (int i = 0; i < G.size(); i++) {

        LinkedNode* n1 = graph->findNode(G[i].second.first);
        LinkedNode* n2 = graph->findNode(G[i].second.second);

        uP = findParent(n1);
        vP = findParent(n2);

        if (uP != vP) {
            T.push_back(G[i]);
            unionSet(uP, vP);
        }
        
    }
}

void Kruskal::print()
{
    cout << "Edge : " << " Weight : " << endl;
    for (int i = 0; i < T.size(); i++) {

        cout << T[i].second.first << "-" << T[i].second.second << "        " << T[i].first << endl;
    }
}
