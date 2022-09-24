#include "Prim.h"
#include "Kruskal.h"
#include "Borukva.h"
#include <chrono>
#include <ctime>
using namespace std::chrono;
using namespace std;

void generate(int* array1, int* edges, int n, int numEdg) {

	for (int i = 0; i < n; i++) {
		array1[i] = i;
	}

	for (int i = 1; i <= numEdg; i++) {

		edges[i] = i;
	}
}
int main() {

	int n = 1000;
	int numEdg = 10 * n;

	int* array1 = new int[n];
	int* edges =  new  int[ numEdg];
	generate(array1, edges, n, numEdg);

	Prim* prim = new Prim();
	
	for (int i = 0; i < n; i++) {
		prim->graph->insertNode(array1[i]);
	}

	for (int i = 1 ; i <= numEdg; i++) {
		int node1 = array1[rand() % n];
		int node2 = array1[rand() % n];
		while (node2 == node1) {
			 node2 = array1[rand() % n];
		}
		prim->graph->insertEdge(node1,node2 , edges[i]);
	}
	LinkedNode* nodeP = prim->graph->getStart();
	int num = numEdg + 1;
	while (nodeP != NULL){
		Edge* adj = nodeP->adj;
		if (adj == NULL) {
			prim->graph->insertEdge(nodeP->node, nodeP->node + 1, num);
		}
		num++;
		nodeP = nodeP->next;

	}
	cout << "Prim's Algoritham: " << endl;

	//prim->graph->print();

	cout << "Rezultat: " << endl;
	auto start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	GraphAsList* rez = prim->mst();
	auto ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "Elapsed time: " << ms << "microseconds\n";
	cout << "--------------------------------------------------------------------------------" << endl;
	rez->print();
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	cout << "Kruskal's algoritham : " << endl;
	Kruskal* kruskal = new Kruskal();
	for (int i = 0; i < n; i++) {
		kruskal->graph->insertNode(array1[i]);
	}
	for (int i = 1; i <= numEdg; i++) {
		int node1 = array1[rand() % n];
		int node2 = array1[rand() % n];
		while (node2 == node1) {
			node2 = array1[rand() % n];
		}
		kruskal->graph->insertEdge(node1, node2, edges[i]);
		kruskal->AddWeightEdge(node1, node2, edges[i]);
	}
	nodeP = kruskal->graph->getStart();
	num = numEdg + 1;
	while (nodeP != NULL) {
		Edge* adj = nodeP->adj;
		if (adj == NULL) {
			kruskal->graph->insertEdge(nodeP->node, nodeP->node + 1, num);
			kruskal->AddWeightEdge(nodeP->node, nodeP->node + 1, num);
		}
		num++;
		nodeP = nodeP->next;

	}
	start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	kruskal->kruskal();
	ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "Elapsed time: " << ms << "microseconds\n";
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "Rezultat: " << endl;
	kruskal->print();
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	cout << "Boruvka's algoritham: " << endl;

	Borukva* borukva = new Borukva();
	Edge* edg = NULL;

	for (int i = 0; i < n; i++) {
		borukva->graph->insertNode(array1[i]);
	}
	borukva->Initialize();

	for (int i = 1; i <= numEdg; i++) {
		int node1 = array1[rand() % n];
		int node2 = array1[rand() % n];
		while (node2 == node1) {
			node2 = array1[rand() % n];
		}
		borukva->graph->insertEdge(node1, node2, edges[i]);
		edg = borukva->graph->findEdge(node1, node2);
		borukva->addEdge(edg);
	}
	nodeP = borukva->graph->getStart();
	num = numEdg + 1;
	while (nodeP != NULL) {
		Edge* adj = nodeP->adj;
		if (adj == NULL) {
			borukva->graph->insertEdge(nodeP->node, nodeP->node + 1, num);
			edg = borukva->graph->findEdge(nodeP->node, nodeP->node + 1);
			borukva->addEdge(edg);
		}
		
		num++;
		nodeP = nodeP->next;
	}
	start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	borukva->boruvka();
	ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "\nElapsed time: " << ms << "microseconds\n";
	cout << "--------------------------------------------------------------------------------" << endl;
	
	return 0;
}