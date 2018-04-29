#include "Points.h"
#include <cstdlib>
#include <cmath>

void MakePoints(int children, Graph & graph){
	vector<pair<int, int>> point;
	srand(children);
	for (int i = 0; i < graph.Size(); i++) {
		double u = 2 * float(rand()) / RAND_MAX - 1;
		double v = sqrt(1 - u*u)*(2 * float(rand()) / RAND_MAX - 1);
		double s = u*u + v*v;
		double p = sqrt(-2 * log(s) / s);
		if (abs(s - 1) < 0.00001) p = 0;
		double x = 100 * u*p;
		double y = 100 * v*p;
		point.push_back(make_pair(x, y));
		for (int j = 0; j < i; j++) {
			graph.AddEdge(i, j, sqrt(pow(x - point[j].first, 2.0) + pow(y - point[j].second, 2.0)));
		}
	}
}