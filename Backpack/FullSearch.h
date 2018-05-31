#pragma once
#include "Solver.h"
#include <list>

using namespace std;

class FullSearch :
	public Solver {
public:
	FullSearch();
	~FullSearch();

	virtual bool* solve(Package* packages, int n, int b, int& maxValue) override;
private:
	bool* f(Package* packages, int b, int n, list<bool> path, int i, int& value);
};

