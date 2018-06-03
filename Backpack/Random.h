#pragma once
#include "Solver.h"
#include <list>
#include <stack>

using namespace std;

class Random :
	public Solver {
public:
	Random();
	~Random();

	virtual bool* solve(Package* packages, int n, int b, int& maxValue) override;

	virtual string getName() override;

private:
	bool* f(Package* packages, int b, int n, list<bool>& path, int i, int& value);
};

