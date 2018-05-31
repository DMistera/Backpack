#pragma once
#include "Package.h"
class Solver {
public:
	Solver();
	virtual bool* solve(Package* packages, int n, int b, int& maxValue) = 0;
	~Solver();
protected:
	int evaluate(Package* packages, int b, int n, bool* solution);
};

