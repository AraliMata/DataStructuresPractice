#pragma once
#include "Edge.h"
#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Graph
{
private:

	vector<vector<int>> adjList;
	vector <vector<int>> adjMatrix;
	bool created = false;

	void initialize(int);

	void createGraph(vector<Edge> const&);

	void DFS(int, int, vector<bool>&);

	void BFS(queue<int>&, vector<bool>&);

public:

	Graph(int);

	Graph(vector<Edge> const&, int);
	
	void loadGraph(int N, string);

	void DFS(int);

	void BFS(int);

};

