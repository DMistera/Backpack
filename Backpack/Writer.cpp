#include "Writer.h"
#include <fstream>
#include <iomanip> 

Writer::Writer() {
}


Writer::~Writer() {
}

void Writer::add(int argument, long value) {
	Node n;
	n.argument = argument;
	n.value = value;
	nodes.push_back(n);
}

void Writer::write(string filename) {
	ofstream file;
	file.open(filename + ".txt");
	for (Node n : nodes) {
		file << n.argument << ":" << std::setprecision(9)<< n.value << ";" << endl;
	}
	file.close();
}