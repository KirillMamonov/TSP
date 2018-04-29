#include "Comparator.h"

bool Comparator::operator()(const vector<double>& a, const vector<double>& b) const {
	if (a[2] < b[2]) return true;
	return false;
}