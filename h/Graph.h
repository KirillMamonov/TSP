/*Граф на котором нужно найти минимальный путь*/

#ifndef GraphH
#define GraphH

#include <vector>

using namespace std;

class Graph {
	int n;
	vector<vector<double>> graph;

public:
	Graph(int countVert);
	Graph();

	void AddEdge(int from, int to, double weight);

	void GetNext(int i, vector<pair<int, double>>& next) const;

	const vector<vector<double>> GetGraph() const;

	double GetWeight(int from, int to) const;

	int Size();

	Graph(const Graph&) = delete;

	Graph& operator = (Graph& g);

	~Graph() {};
};

#endif