
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

int main() {
	srand(time(nullptr));

	int n = 100;
	Package* packages = generate(n);
	for (int i = 0; i < n; i++) {
		cout << i << ": Size:" << packages[i].size << " Value:" << packages[i].value << endl;
	}
	FullSearchOptimized f;
	Dynamic d;
	int maxValue = -1;
	int v2 = -1;
	bool* solution = f.solve(packages, n, 1000, maxValue);
	bool* solution2 = d.solve(packages, n, 1000, v2);
	cout << "Max: " << maxValue << endl;
	for (int i = 0; i < n; i++) {
		if (solution[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (solution2[i]) {
			cout << i << " ";
		}
	}
	system("PAUSE");
	return 0;
}