#include "test.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include "points.h"
#include "Enumeration.h"
#include "MinOst.h"

TestResults::TestResults(bool success, time_t time, double ansEnum, double ansMinOst, double error) :
	success(success), time(time), ansEnum(ansEnum), ansMinOst(ansMinOst), error(error) {}

TestResults runTests(int maxNumbTest, const vector<int> &numbVert, double criteria) {
	vector<int> testNumb;
	for (int i = 0; i < maxNumbTest; i++) testNumb.push_back(i);
	return runTests(testNumb, numbVert, criteria);
}

TestResults runTests(const vector<int> &testNumb, const vector<int> &numbVert, double criteria){
	int success = 0;
	int fail = 0;
	time_t timer = 0;
	double avgMinOst = 0;
	double avgEnum = 0;
	double stDeviation = 0;	//Стандартное отклонение
	//Запускаем тест для всех кол-ств вершин и детей
	for (int testI : testNumb) {
		for (int n : numbVert) {
			TestResults results = runTest(testI, n, criteria);
			results.success ? success++ : fail++;
			timer += results.time;
			avgMinOst += results.ansMinOst;
			avgEnum += results.ansEnum;
			stDeviation += results.error;
		}
	}
	avgEnum /= fail + success;
	avgMinOst /= fail + success;
	stDeviation = sqrt(stDeviation) / (fail + success);
	return TestResults(fail == 0, timer, avgEnum, avgMinOst, stDeviation);
}

TestResults runTest(int testI, int n, double criteria) {
	Graph graph(n);
	MakePoints(testI, graph);
	time_t timer = -time(NULL);	//Запуск теста
	Enumeration permutations;
	MinPath minPath;
	double lenEnum = permutations(graph);
	double lenMinOst = minPath(graph);
	timer += time(NULL);
	(lenMinOst / lenEnum <= criteria && 1 <= lenMinOst / lenEnum) ? cout << "SUCCESS" : cout << "FAIL";	//Результаты теста
	double err = abs(lenMinOst - lenEnum) / lenEnum * 100;
	cout << " " << (int)((100 - err >= 0) ? (100 - err) : (0)) << "%\n"
		<< fixed << setprecision(2)
		<< "Enumeration Answer: " << lenEnum << " MinOst Answer: " << lenMinOst
		<< " Test " << testI
		<< ", N: " << n << "\n\n";
	return TestResults(lenMinOst / lenEnum <= criteria && 1 <= lenMinOst / lenEnum, timer, lenEnum, lenMinOst, abs(lenMinOst - lenEnum));
}

TestResults runTests(const vector<int> &testNumb, int maxN, double criteria){
	vector<int> numbVert;
	for (int i = 2; i <= maxN; i++) numbVert.push_back(i);
	return runTests(testNumb, numbVert, criteria);
}