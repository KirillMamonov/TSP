/*������� ����������� ���� � ������� ������������ ��������� ������*/

#include "Graph.h"

class MinPath {
	void DFS(Graph &mst, int dot);	//���� ������� ���� � �����

	void MakeTree(Graph &graph, Graph & result) const;

	vector<double> path;	//���� �������� � DFS
	vector<bool> visit;
	int n;					//���-�� ������
public:
	double operator()(Graph & graph);
};