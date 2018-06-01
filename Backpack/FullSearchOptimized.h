#pragma once
#include "Solver.h"
#include <list>

using namespace std;

class FullSearchOptimized :
	public Solver {
public:
	FullSearchOptimized();
	~FullSearchOptimized();

	virtual bool* solve(Package* packages, int n, int b, int& maxValue) override;

private:
	bool* f(Package* packages, int b, int n, list<bool>& path, int i, int& value, int sum);
};

