#pragma once
#include "Solver.h"
#include <list>

using namespace std;

class Dynamic :
	public Solver {
public:
	Dynamic();
	~Dynamic();

	virtual bool* solve(Package* packages, int n, int b, int& maxValue) override;
private:
	int f(Package* packages, int i, int l, list<int>& solution);
};

