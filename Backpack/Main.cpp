
#include <iostream>
#include "Package.h"
#include <random>
#include <time.h>
#include "FullSearch.h"
#include "FullSearchOptimized.h"
#include "Dynamic.h"

Package* generate(int n) {
	Package* packages = new Package[n];
	for (int i = 0; i < n; i++) {
		packages[i].size = 100 + rand() % 990;
		packages[i].value = 100 + rand() % 9990;
	}
	return packages;
}

int getB(Package* packages, int n, float percent) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += packages[i].size;
	}
	return (int)(sum*percent);
}

void test() {
	FullSearch bf1;
	FullSearchOptimized bf2;
	Dynamic pd;
	int n = 10;
	Package* data = generate(n);
	int b = 1000;
	int maxV;
	bool* s1 = bf1.solve(data, n, b, maxV);
	bool* s2 = bf2.solve(data, n, b, maxV);
	bool* s3 = pd.solve(data, n, b, maxV);
	for (int i = 0; i < n; i++) {
		if (s1[i] != s2[i] || s2[i] != s3[i]) {
			cout << "Something went wrong!" << endl;
			break;
		}
	}
}

int main() {
	srand(time(nullptr));

	test();

	long bf1Time = 0;
	long bf2Time = 0;
	long pdTime = 0;

	FullSearch bf1;
	FullSearchOptimized bf2;
	Dynamic pd;

	int measures = 30;
	int step = 1;
	int n = 1;
	while (pdTime < 3000 * 1000) {
		Package* data = generate(n);
		int b = getB(data, n, 0.5f);

		int bf1Value = -1;
		if (bf1Time < 3000 * 1000) {
			bf1Time = bf1.solveAndTime(data, n, b, bf1Value);
		}

		int bf2Value = -1;
		if (bf2Time < 3000 * 1000) {
			bf2Time = bf2.solveAndTime(data, n, b, bf2Value);
		}
		else {
			step = 25;
		}

		int pdValue = -1;
		pdTime = pd.solveAndTime(data, n, b, pdValue);

		cout << "Finished for n = " << n << endl;
		n += step;
	}

	bf1.write();
	bf2.write();
	pd.write();

	system("PAUSE");
	return 0;
}