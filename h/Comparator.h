/*Компаратор для сортировки графа по весу ребра при построении минимального остовного дерева*/

#include <vector>

using namespace std;

struct Comparator {
	bool operator()(const vector<double>& a, const vector<double>& b) const;
};