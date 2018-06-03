#include "Random.h"
#include <list>



Random::Random() {
}


Random::~Random() {
}

bool* Random::solve(Package* packages, int n, int b, int& maxValue) {
	int i=0,s=0;
	bool* solution = new bool[n];
	while (s + packages[i].size < b)
	{
		s += packages[i].size;
		solution[i++] = true;
	}
	return solution;
}

std::string Random::getName() {
	return "Losowo";
}