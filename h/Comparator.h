/*���������� ��� ���������� ����� �� ���� ����� ��� ���������� ������������ ��������� ������*/

#include <vector>

using namespace std;

struct Comparator {
	bool operator()(const vector<double>& a, const vector<double>& b) const;
};