#include "FullSearch.h"
#include <list>



FullSearch::FullSearch() {
}


FullSearch::~FullSearch() {
}

bool* FullSearch::solve(Package* packages, int n, int b, int& maxValue) {
	return f(packages, b, n, list<bool>(), 0, maxValue);
}

bool* FullSearch::f(Package* packages, int b, int n, list<bool> path, int i, int& value) {
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
		list<bool> left = path;
		left.push_back(true);
		list<bool> right = path;
		right.push_back(false);
		int l;
		int r;
		bool* solL = f(packages, b, n, left, i + 1, l);
		bool* solR = f(packages, b, n, right, i + 1, r);
		if (l > r) {
			value = l;
			delete solR;
			return solL;
		}
		else {
			value = r;
			delete solL;
			return solR;
		}
	}
}
