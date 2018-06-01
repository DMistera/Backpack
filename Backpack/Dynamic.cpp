#include "Dynamic.h"



Dynamic::Dynamic() {
}


Dynamic::~Dynamic() {
}

bool* Dynamic::solve(Package* packages, int n, int b, int& maxValue) {
	list<int> indexes;
	maxValue = f(packages, n, b, indexes);
	bool* solution = new bool[n];
	for (int i = 0; i < n; i++) {
		solution[i] = false;
	}
	for (int i : indexes) {
		solution[i] = true;
	}
	return solution;
}

int Dynamic::f(Package* packages, int i, int l, list<int>& solution) {
	if (i == -1 || l == 0) {
		return 0;
	}
	else {
		if (packages[i].size > l) {
			return f(packages, i - 1, l, solution);
		}
		else {
			list<int> sol1;
			list<int> sol2;
			int v1 = f(packages, i - 1, l, sol1);
			int v2 = f(packages, i - 1, l - packages[i].size, sol2) + packages[i].value;
			if (v1 > v2) {
				solution = sol1;
				return v1;
			}
			else {
				sol2.push_back(i);
				solution = sol2;
				return v2;
			}
		}
	}
}
