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

	virtual string getName() override;

private:
	int getIndex(int b, int i, int l);
};

