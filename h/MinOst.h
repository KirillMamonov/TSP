/*Находит минимальный путь с помощью минимального остовного дерева*/

#include "Graph.h"

class MinPath {
	void DFS(Graph &mst, int dot);	//Ищет Эйлеров путь в графе

	void MakeTree(Graph &graph, Graph & result) const;

	vector<double> path;	//Путь найденый в DFS
	vector<bool> visit;
	int n;					//Кол-во вершин
public:
	double operator()(Graph & graph);
};