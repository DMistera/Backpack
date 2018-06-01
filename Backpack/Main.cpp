
#include <iostream>
#include "Package.h"
#include <random>
#include <time.h>
#include "FullSearch.h"
#include "FullSearchOptimized.h"

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
	int maxValue = -1;
	bool* solution = f.solve(packages, n, 1000, maxValue);
	cout << "Max: " << maxValue << endl;
	for (int i = 0; i < n; i++) {
		if (solution[i]) {
			cout << i << " ";
		}
	}
	system("PAUSE");
	return 0;
}