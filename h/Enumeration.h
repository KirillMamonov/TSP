/*������� ����������� ��������� ��� ��������� � �������� � ������� ���. ���. ������*/

#include "Graph.h"

class Enumeration {
	int n;
	vector<int> path;
	double minLen;
	Graph* linkGr;

	void Permutations(int depth);	//��������� ������������

	double GetLen() const;			//����� ����������� ����
public:
	double operator()(Graph & graph);
};