#include "FullSearch.h"
#include <list>



FullSearch::FullSearch() {
}


FullSearch::~FullSearch() {
}

bool* FullSearch::solve(Package* packages, int n, int b, int& maxValue) {
	list<bool> path;
	return f(packages, b, n, path, 0, maxValue);
}

std::string FullSearch::getName() {
	return "Pelny przeglad";
}

bool* FullSearch::f(Package* packages, int b, int n, list<bool>& path, int i, int& value) {
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
		int l;
		int r;
		path.push_back(true);
		bool* solL = f(packages, b, n, path, i + 1, l);
		path.pop_back();
		path.push_back(false);
		bool* solR = f(packages, b, n, path, i + 1, r);
		path.pop_back();
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
