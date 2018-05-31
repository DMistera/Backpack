#include "Solver.h"



Solver::Solver() {
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
