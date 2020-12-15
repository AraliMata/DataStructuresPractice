#include <iostream>
#include "Graph.h"

int main()
{
    int nodos = 13;

	Graph graph(nodos);

	graph.loadGraph(nodos, "grafo1.txt");

	cout << "DFS: ";
	graph.DFS(nodos);
	cout << "BFS: ";
	graph.BFS(nodos);   
}
