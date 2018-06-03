
#include <iostream>
#include "Package.h"
#include <random>
#include <time.h>
#include "FullSearch.h"
#include "FullSearchOptimized.h"
#include "Random.h"
#include "GH2.h"
#include "GH3.h"
#include "GH4.h"
#include "Dynamic.h"

class ErrorCalculator {
public:
	void add(int pdValue, int ghValue) {
		if (ghValue != 0) {
			float v = 100.0*(float)(pdValue - ghValue) / (float)pdValue;
			sum += v;
			count++;
		}
	}
	void print(string name) {
		float v = sum / (float)count;
		cout << name << " error: " << v << endl;
	}
private:
	float sum = 0;
	int count = 0;
};

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
	Random rand;

	int n = 10;
	Package* data = generate(n);
	int b = 1000;
	int maxV;
	bool* s1 = bf1.solve(data, n, b, maxV);
	bool* s2 = bf2.solve(data, n, b, maxV);
	bool* s3 = pd.solve(data, n, b, maxV);
	bool* s4 = rand.solve(data, n, b, maxV);
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
	long randTime = 0;
	long gh2Time = 0;
	long gh3Time = 0;
	long gh4Time = 0;


	FullSearch bf1;
	FullSearchOptimized bf2;
	Dynamic pd;
	Random rand;
	GH2 gh2;
	GH3 gh3;
	GH4 gh4;

	ErrorCalculator gh1Err;
	ErrorCalculator gh2Err;
	ErrorCalculator gh3Err;
	ErrorCalculator gh4Err;

	int measures = 30;
	int step = 1;
	int n = 1;
	while (pdTime < 3000 * 1000) {
		Package* data = generate(n);
		int b = getB(data, n, 0.75f);

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
		int randValue = -1;
		randTime = rand.solveAndTime(data, n, b, randValue);
		gh1Err.add(pdValue, randValue);
		int gh2Value = -1;
		gh2Time = gh2.solveAndTime(data, n, b, gh2Value);
		gh2Err.add(pdValue, gh2Value);
		int gh3Value = -1;
		gh3Time = gh3.solveAndTime(data, n, b, gh3Value);
		gh3Err.add(pdValue, gh3Value);
		int gh4Value = -1;
		gh4Time = gh4.solveAndTime(data, n, b, gh4Value);
		gh4Err.add(pdValue, gh4Value);

		if (gh2Value == -1 || gh3Value == -1 || gh4Value == -1) {
			cout << "Max value not calculated" << endl;
		}

		cout << "Finished for n = " << n << endl;
		n += step;
	}

	gh1Err.print("Random");
	gh2Err.print("Min");
	gh3Err.print("Max");
	gh4Err.print("Ratio");

	bf1.write();
	bf2.write();
	pd.write();
	rand.write();
	gh2.write();
	gh3.write();
	gh4.write();

	system("PAUSE");
	return 0;
}