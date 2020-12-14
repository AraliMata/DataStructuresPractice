#include "Graph.h"

Graph::Graph(int N) {

	initialize(N);
}

Graph::Graph(vector<Edge> const& edges, int N) {
	
	initialize(N);

	if(N != 0)
		createGraph(edges);
}

void Graph::initialize(int N){

	adjList.resize(N);
	adjMatrix.resize(N);

	for (int i = 0; i < N; i++) {

		adjMatrix[i].resize(N);
		for (int j = 0; j < N; j++) 
			adjMatrix[i][j] = 0;
	}
}

void Graph::createGraph(vector<Edge> const& edges){

	for (auto& edge : edges){

		adjList[edge.src].push_back(edge.dest);
		adjList[edge.dest].push_back(edge.src);

		adjMatrix[edge.src][edge.dest] = 1;
		adjMatrix[edge.dest][edge.src] = 1;
	}

	created = true;
}

void Graph::DFS(int start, int N, vector<bool>& visited){

	cout << start << " ";

	visited[start] = true;

	for (int i = 0; i < N; i++) {

		if (adjMatrix[start][i] == 1 && !visited[i]) {
			DFS(i, N, visited);
		}
	}
}



void Graph::BFS(queue<int>& q, vector<bool>& discovered){

	if (q.empty())
		return;

	int v = q.front();
	q.pop();

	cout << v << " ";

	for (int u : adjList[v]) {
		if (!discovered[u]) {
			discovered[u] = true;
			q.push(u);
		}
	}

	BFS(q, discovered);
}

void Graph::DFS(int N)
{
	if (created) {

		vector<bool> visited(N, false);
		vector<vector<int>>;

		for (int i = 0; i < N; i++) {
			if (!visited[i])
				DFS(i, N, visited);
		}

	}
	else
		cout << "El grafo se encuentra vacio";

	cout << endl;
}

void Graph::BFS(int N){

	if (created) {
		queue<int> q;
		vector<bool> discovered(N, false);

		for (int i = 0; i < N; i++) {
			if (!discovered[i]) {
				discovered[i] = true;
				q.push(i);
				BFS(q, discovered);
			}
		}

	}
	else
		cout << "El grafo se encuentra vacio";

	cout << endl;
}

void Graph::loadGraph(int N, string fileName){

	vector<Edge> edges;
	int src, dest;
	string line, srcS, destS;

	fstream file;

	file.open(fileName);

	if (file.is_open()) {

		while (getline(file, line)) {

			stringstream s(line);
			getline(s, srcS, ',');
			getline(s, destS, ',');

			stringstream ss1(srcS);
			stringstream ss2(destS);

			ss1 >> src;
			ss2 >> dest;

			Edge edgeTemp = { src, dest };

			edges.push_back(edgeTemp);
		}

		if (N != 0)
			createGraph(edges);
	}
	else {
		cout << "El archivo no pudo ser abierto" << endl;
	}
}


