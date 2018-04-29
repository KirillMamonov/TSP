#include "DSU.h"

	DSU::DSU(int n) : size(n), parents(n + 1), deep(n + 1) {
		for (int i = 1; i <= size; ++i) parents[i] = i;
	}

	double DSU::get(int i) {
		if (parents[i] != i) parents[i] = get(parents[i]);
		return parents[i];
	}

	void DSU::union_(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) return;
		if (deep[x] == deep[y]) deep[x]+=1;
		if (deep[x] < deep[y]) parents[x] = y;
		else parents[y] = x;
	}