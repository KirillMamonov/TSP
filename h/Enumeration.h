/*Решение рекурсивным перебором для сравнения с решением с помощью мин. ост. дерева*/

#include "Graph.h"

class Enumeration {
	int n;
	vector<int> path;
	double minLen;
	Graph* linkGr;

	void Permutations(int depth);	//Реализует перестановку

	double GetLen() const;			//Длина полученного пути
public:
	double operator()(Graph & graph);
};