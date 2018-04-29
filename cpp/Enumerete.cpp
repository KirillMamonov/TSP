#include "Enumeration.h"
#include <algorithm>

double Enumeration::GetLen() const {
	double tour = linkGr->GetWeight(path[n - 2], 0) + linkGr->GetWeight(0, path[0]);
	for (int i = 1; i < n - 1; i++) tour += linkGr->GetWeight(path[i - 1], path[i]);
	return tour;
}

void Enumeration::Permutations(int depth){
	if (depth == path.size()) {
		double tour = GetLen();
		if (tour < minLen) minLen = tour;
		return;
	}
	for (int i = 0; i <= depth; i++) {
		swap(path[i], path[depth]);
		Permutations(depth + 1);
		swap(path[i], path[depth]);
	}
}

double Enumeration::operator()(Graph & graph){
	linkGr = &graph;
	n = graph.Size();
	if (n < 2) return 0;
	path.clear();
	for (int i = 1; i < n; i++) path.push_back(i);
	minLen = GetLen();
	Permutations(1);
	return minLen;
}