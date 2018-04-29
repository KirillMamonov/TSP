#include "test.h"
#include<iostream>

using namespace std;

int main() {
	vector<int> iterations{ 60 };
	vector<int> numberVert{ 10 };
	cout << "Results for 10 points, 10 tests:\n";
	runTests(10, numberVert);
	cout << "\n----------------------------------------\n";
	cout << "\nResults for 2..10 points, 1 test:\n";
	runTests(iterations, 10);
	system("pause");
}