#include "MinOst.h"
#include "DSU.h"

void MinPath::MakeTree(Graph &graph, Graph &result) const {
	DSU dsu(graph.Size());
	for (vector<double> edge : graph.GetGraph())
		if (dsu.get(edge[0]) != dsu.get(edge[1])) {
			dsu.union_(edge[0], edge[1]);
			result.AddEdge(edge[0], edge[1], edge[2]);
		}
}

void MinPath::DFS(Graph & minOst, int dot) {
	vector<pair<int, double>> nextVert(n);
	minOst.GetNext(dot, nextVert);
	for (const pair<int, double>& vert : nextVert) {
		if (!visit[vert.first]) {
			visit[vert.first] = true;
			path.push_back(vert.first);
			DFS(minOst, vert.first);
		}
	}
}

double MinPath::operator()(Graph & graph){
	n = graph.Size();
	visit.assign(n, false);
	Graph minOst(n);
	MakeTree(graph, minOst);
	visit[0] = true;
	DFS(minOst, 0);
	double lengPath = graph.GetWeight(path[n - 2], 0) + graph.GetWeight(0, path[0]);
	for (int i = 1; i < n - 1; ++i)
		lengPath = lengPath + graph.GetWeight(path[i - 1], path[i]);
	return lengPath;
}