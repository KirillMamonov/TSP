#include"Graph.h"
#include"Comparator.h"
#include<algorithm>

Graph::Graph(int countVert) : n(countVert), graph(n, vector<double>(n)) {}
Graph::Graph() : graph(0) {}

double Graph::GetWeight(int from, int to) const {
	return graph[from][to];
}

void Graph::AddEdge(int from, int to, double weight) {
	graph[from][to] = weight;
	graph[to][from] = weight;
}

void Graph::GetNext(int from, vector<pair<int, double>>& next) const {
	for (int i = 0; i < n; ++i)
		if (graph[from][i] != 0) next.push_back(make_pair(i, graph[from][i]));
}

const vector<vector<double>> Graph::GetGraph() const {
	vector<vector<double>> res;
	int k = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (graph[i][j] != 0 && i>j)
				res.push_back({ (double)i, (double)j, graph[i][j] });
	k++;
	sort(res.begin(), res.end(), Comparator());
	return res;
}

int Graph::Size() { return n; }

Graph& Graph::operator = (Graph& g) {
	graph = g.graph;
	n = g.n;
	return*this;
}