/*����������������� ��������� �������, ��������� ������ ������� ����������� ���������
� ����� �� ���. ���. ����� c ��������� ����*/
#include <vector>

using namespace std;

struct TestResults {
	double ansEnum;	//����� ������� ����������� ���������
	double ansMinOst;	//����� �� ���. ���. ������
	double error;
	bool success;	//���� �������
	time_t time;	//�� ������� ������� ����
	TestResults(bool success, time_t time, double ansBF, double ansMST, double error);
};

//��������� �� 0 �� maxNumbTest ������ ��� ������� ���-�� ������ �� numbVert
TestResults runTests(int maxNumbTest, const vector<int> &numbVert, double criteria = 2);

//��������� ���� ��� ������� �������, � ���-�� ������
TestResults runTests(const vector<int> &testNumb, const vector<int> &numbVert, double criteria);

//���� � ������������ ���-��� ������
TestResults runTest(int testI, int n, double criteria);

//��� ������� �������� testI ������� testNumb ��������� testI ������ ��� ���-�� ������ �� 2 �� maxN,
//�������� - ����������� ���������� ��������� ������ �� ���. ���. ������ � ������ ����������� ���������
TestResults runTests(const vector<int> &testNumb, int maxN, double criteria = 2);