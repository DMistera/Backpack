#include "Solver.h"
#include <chrono>



Solver::Solver() {
}


long Solver::solveAndTime(Package* packages, int n, int b, int& maxValue) {
	auto begin = std::chrono::steady_clock::now();
	bool* solution = solve(packages, n, b, maxValue);
	delete solution;
	auto end = std::chrono::steady_clock::now();
	long time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	writer.add(n, time);
	return time;
}

void Solver::write(string add) {
	writer.write("output\\" + getName() + add + ".txt");
}

Solver::~Solver() {
}

int Solver::evaluate(Package* packages, int b, int n, bool* solution) {
	int sum = 0;
	int sumv = 0;
	int i = 0;
	while (sum < b && i < n) {
		if (solution[i]) {
			sum += packages[i].size;
			sumv += packages[i].value;
		}
		i++;
	}
	if (sum <= b) {
		return sumv;
	}
	else {
		return 0;
	}
}
