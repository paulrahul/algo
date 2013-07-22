/*
ID: paul.ra1
LANG: C++
TASK: milk3
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int w[3];
set<int> ans;

void transfer(vector<int> curr, int s, int t) {	
	int to_fill = w[t] - curr[t];
	
	if (curr[s] < to_fill) {
		curr[t] += curr[s];
		curr[s] = 0; 
	} else {
		curr[s] -= curr[t];
		curr[t] = w[t];
	}
	
	if (curr[0] == 0) {
		ans.insert(curr[2]);
		return;
	}

	cout << curr[0] << " " << curr[1] << " " << curr[2] << endl;
	
	// a -> b
	transfer(curr, 0, 1);
	if (1) return;
	// b -> a
	transfer(curr, 1, 0);

	transfer(curr, 1, 2);
	// b -> c
	// c -> b
	transfer(curr, 2, 1);

	// c -> a
	transfer(curr, 2, 0);
	// a -> c
	transfer(curr, 0, 2);	
}

int main(int argc, char** argv) {
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	
	fin >> w[0] >> w[1] >> w[2];
	vector<int> curr(3, 0);
	curr[2] = w[2];
	
	// c->a
	transfer(curr, 2, 0);
	// c->b
	transfer(curr, 2, 1);
	
	vector<int> answers(ans.begin(), ans.end());
	sort(answers.begin(), answers.end());
	for (int i = 0; i < answers.size() - 1; ++i) {
		fout << answers[i] << " ";
	}
	fout << answers[answers.size() - 1] << endl;
	
	return 0;
}