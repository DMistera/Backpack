#pragma once
#include "Solver.h"
#include <list>
#include <stack>

using namespace std;

class GH3 :
	public Solver {
public:
	GH3();
	~GH3();

	virtual bool* solve(Package* packages, int n, int b, int& maxValue) override;

	virtual string getName() override;

private:
	void QS(Package2* pack2, int b, int n);
};

