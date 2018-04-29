/*јвтоматизированно тестирует решение, сравнива€ ответы решени€ рекурсивным перебором
и ответ на мин. ост. дерев c Ёйлеровым путЄм*/
#include <vector>

using namespace std;

struct TestResults {
	double ansEnum;	//ќтвет решени€ рекурсивным перебором
	double ansMinOst;	//ќтвет на мин. ост. дереве
	double error;
	bool success;	//“ест пройден
	time_t time;	//«а сколько пройден тест
	TestResults(bool success, time_t time, double ansBF, double ansMST, double error);
};

//«апускает от 0 до maxNumbTest тестов дл€ каждого кол-ва вершин из numbVert
TestResults runTests(int maxNumbTest, const vector<int> &numbVert, double criteria = 2);

//«апускает тест дл€ каждого потомка, и кол-ва вершин
TestResults runTests(const vector<int> &testNumb, const vector<int> &numbVert, double criteria);

//“ест с определенным кол-вом вершин
TestResults runTest(int testI, int n, double criteria);

//ƒл€ каждого элемента testI вектора testNumb запускает testI тестов дл€ кол-ва вершин от 2 до maxN,
//критерий - максимально допустимое отношение ответа на мин. ост. дереве к ответу рекурсивным перебором
TestResults runTests(const vector<int> &testNumb, int maxN, double criteria = 2);