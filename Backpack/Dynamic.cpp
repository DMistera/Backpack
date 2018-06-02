#include "Dynamic.h"



Dynamic::Dynamic() {
}


Dynamic::~Dynamic() {

}

std::string Dynamic::getName() {
	return "Programowanie dynamiczne";
}


/* Failed Attempt

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
*/

int Dynamic::getIndex(int b, int i, int l) {
	int v = (b + 1)*i + (l + 1) - 1;
	if (v < 0) {
		throw exception("Out of bounds!");
	}
	return v;
}

bool* Dynamic::solve(Package* packages, int n, int b, int& maxValue) {
	int* table = new int[(n + 1)*(b + 1)];
	for (int i = 0; i <= n; i++) {
		for (int l = 0; l <= b; l++) {
			if (i == 0 || l == 0) {
				table[getIndex(b, i, l)] = 0;
			}
			else {
				if (packages[i - 1].size > l) {
					table[getIndex(b, i, l)] = table[getIndex(b, i - 1, l)];
				}
				else {
					int v1 = table[getIndex(b, i - 1, l)];
					int v2 = 0;
					if (l - packages[i - 1].size >= 0) {
						v2 = table[getIndex(b, i - 1, l - packages[i - 1].size)] + packages[i - 1].value;
					}
					table[getIndex(b, i, l)] = v1 > v2 ? v1 : v2;
				}
			}
		}
	}
	maxValue = table[getIndex(b, n, b)];
	bool* solution = new bool[n];
	for (int i = 0; i < n; i++) {
		solution[i] = false;
	}
	int ind = b;
	for (int i = n; i > 0; i--) {
		if (table[getIndex(b, i, ind)] != table[getIndex(b, i - 1, ind)]) {
			ind -= packages[i - 1].size;
			solution[i - 1] = true;
		}
	}
	delete table;
	return solution;
}
