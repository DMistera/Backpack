#include "FullSearchOptimized.h"



FullSearchOptimized::FullSearchOptimized() {
}


FullSearchOptimized::~FullSearchOptimized() {
}

bool* FullSearchOptimized::solve(Package* packages, int n, int b, int& maxValue) {
	list<bool> path;
	return f(packages, b, n, path, 0, maxValue, 0);
}

bool* FullSearchOptimized::f(Package* packages, int b, int n, list<bool>& path, int i, int& value, int sum) {
	if (i == n) {
		bool* solution = new bool[n];
		int k = 0;
		for (bool b : path) {
			solution[k] = b;
			k++;
		}
		value = evaluate(packages, b, n, solution);
		return solution;
	}
	else {
		int l = 0;
		int r = 0;
		int sum2 = sum + packages[i].size;
		bool* solL = nullptr;
		if (sum2 <= b) {
			path.push_back(true);
			solL = f(packages, b, n, path, i + 1, l, sum2);
			path.pop_back();
		}
		path.push_back(false);
		bool* solR = f(packages, b, n, path, i + 1, r, sum);
		path.pop_back();
		if (l > r) {
			value = l;
			delete solR;
			return solL;
		}
		else {
			value = r;
			if (solL != nullptr) {
				delete solL;
			}
			return solR;
		}
	}
}
