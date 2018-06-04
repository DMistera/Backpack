#pragma once
#include "Package.h"
#include "Writer.h"
#include <string>
class Solver {
public:
	Solver();
	long solveAndTime(Package* packages, int n, int b, int& maxValue);
	virtual bool* solve(Package* packages, int n, int b, int& maxValue) = 0;
	virtual string getName() = 0;
	void write(string add);
	~Solver();
protected:
	int evaluate(Package* packages, int b, int n, bool* solution);
	Writer writer;
};

