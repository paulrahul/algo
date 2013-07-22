/*
ID: paul.ra1
LANG: C++
TASK: ariprog
*/

#include <iostream>
#include <fstream>

using namespace std;

bool bsq[70000];

void precompute(int m) {
	for (int i = 0; i < m - 1; ++i) {
		for (int j = i + 1; j < m; ++j) {
			bsq[i*i + j*j] = true;
		}
	}
}

int main(int argc, char** argv) {
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	
	int n, m;
	fin >> n >> m;
	precompute(m);

	

	return 0;
}