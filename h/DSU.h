/*Система непересекающихся множеств для построения мин. ост. дерева*/

#include <vector>

using namespace std;

class DSU {
	vector<int> parents;
	vector<int> deep;
	int size;

public:
	DSU(int n);

	double get(int i);

	void union_(int x, int y);

	DSU(const DSU&) = delete;

	~DSU() {};
};