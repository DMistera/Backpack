#pragma once
#include "Solver.h"
#include <list>
#include <stack>

using namespace std;

class GH2 :
	public Solver {
public:
	GH2();
	~GH2();

	virtual bool* solve(Package* packages, int n, int b, int& maxValue) override;

	virtual string getName() override;

private:
	void QS(Package2* pack2, int b, int n);
};

