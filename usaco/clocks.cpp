/*
ID: paul.ra1
LANG: C++
TASK: clocks
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

struct node {
	int clock[9];
	int level;
	vector<int> path;
};

string moves[] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};

ifstream fin("clocks.in");
ofstream fout("clocks.out");

void rotate_clock(int clock, int* matrix) {
	// Each clock can have states [0, 1, 2, 3].
	// So each clock needs 2 bits at max. So 18 bits needed in total.
	
	// Get clock current state
	int curr = *matrix & (3 << clock);
	int new_state = (curr + 1) % 4;
	
	// Set the new clock state
	*matrix |= (new_state << clock);
}

bool apply_move(const node& s, int m, int level, node* out) {
	string move = moves[m];
	int len = move.length();
	
	for (int i = 0; i < 9; ++i) out->clock[i] = s.clock[i];
	for (int i = 0; i < len; ++i) {
		int d = move[i] - 'A';
		out->clock[d] = (s.clock[d] + 3) % 12;
	}
	
	out->level = level;
	out->path = s.path;
	out->path.push_back(m + 1);

	int sum = accumulate(out->clock, out->clock + 9, 0);
	if (sum == 0) return true;
	return false;
}

void bfs(vector<node>& q, int level) {
	vector<node> nq;
	vector<node>::iterator iter = q.begin();
	while (iter != q.end()) {
		const node& s = *iter;
		for (int i = 0; i < 9; ++i) {
			node v;
			bool ret = apply_move(s, i, level + 1, &v);
			if (ret) {
				for (int i = 0; i < v.path.size() - 1; ++i) {
					fout << v.path[i] << " ";
				}
				fout << v.path[v.path.size() - 1] << endl;
				return;
			}
			
			nq.push_back(v);
		}
		
		++iter;
	}

	q.clear();
	bfs(nq, level + 1);
}

int main(int argc, char** argv) {
	node init;
	int i = 0;
	while (fin >> init.clock[i]) {
		init.clock[i] %= 12;
		i++;
	}

	init.level = 0;
	
	int sum = accumulate(init.clock, init.clock + 9, 0);
	if (sum == 0) {return 0;}
	
	vector<node> q;
	q.push_back(init);
	bfs(q, 0);
	

	return 0;
}