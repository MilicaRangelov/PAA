#include "BellmanFord.h"
#include "Dijkstra.h"
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

	int n = 100;
	int numEdg = 10* n;

	int* array1 = new int[n];
	int* edges = new  int[numEdg];
	generate(array1, edges, n, numEdg);

	BellmanFord* bf = new BellmanFord();
	for (int i = 0; i < n; i++) {
		bf->graph->insertNode(array1[i]);
	}

	int j = 1;
	for (int i = n-1; i > 1; i--) {
		
		bf->graph->insertEdge(edges[j],i, i-1);
		j++;
	}

	for (int i = n+1; i <= numEdg; i++) {
		int node1 = array1[rand() % n];
		int node2 = array1[rand() % n];
		while (node2 == node1) {
			node2 = array1[rand() % n];
		}
		bf->graph->insertEdge(edges[i], node1, node2);
	}
	
	bf->graph->print();
	
	cout << "Bellman Ford: " << endl;
	cout << "Rezultat: " << endl;
	auto start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	bf->BellmanFordAlg();
	auto ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "Elapsed time: " << ms << "microseconds\n";
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	Dijkstra* dijk = new Dijkstra();

	for (int i = 0; i < n; i++) {
		dijk->graph->insertNode(array1[i]);
	}

	for(int i = 0; i < n-1; i++) {

		dijk->graph->insertEdge(edges[i+1], i, i+1);
	}
	dijk->graph->insertEdge(edges[n], n - 1, 0);

	for (int i = n + 1; i <= numEdg; i++) {
		int node1 = array1[rand() % n];
		int node2 = array1[rand() % n];
		while (node2 == node1) {
			node2 = array1[rand() % n];
		}
		dijk->graph->insertEdge(edges[i], node1, node2);
	}


	cout << "Dijkstrin algoritham: " << endl;
	start = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
	dijk->DijkstraAlg();
	ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() - start;
	cout << "Elapsed time: " << ms << "microseconds\n";
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	return 0;
}
