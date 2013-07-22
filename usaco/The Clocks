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
	//int clocks;
	int prev_node;
	int m;
};

string moves[] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};

ifstream fin("clocks.in");
ofstream fout("clocks.out");

//bool state_visited[300000];
int key_count[9];
node* states[300000];
vector<int> ans;
int source_clock;

int set_bits(int original, int mask, int position) {
	int m1 = ~(3 << position);
	int r1 = original & m1;
	
	int m2 = (mask << position);
	
	int result = (r1 | m2);
	return result;
}

void rotate_clock(int clock, int* matrix) {
	// Each clock can have states [0, 1, 2, 3].
	// So each clock needs 2 bits at max. So 18 bits needed in total.

//	cout << "Rotate clock " << clock << endl;
//	cout << "Initial state " << *matrix << endl;
	
	int position = clock * 2;
	
	// Get clock current state
	int curr = (*matrix & (3 << position)) >> position;
	int new_state = (curr + 1) % 4;
	
	// Set the new clock state
	*matrix = set_bits(*matrix, new_state, position);
//	cout << "Final state " << *matrix << endl;
}

bool apply_move(int s, int m, int* out) {
	string move = moves[m];
	int len = move.length();
	
	*out = s;
	for (int i = 0; i < len; ++i) {
		int d = move[i] - 'A';
		rotate_clock(d, out);
	}
	
	if (*out == 0) return true;
	return false;
}

void print_path(int node) {
	if (states[node]->prev_node == source_clock) {
		fout << states[node]->m;
		return;
	}
	
	print_path(states[node]->prev_node);
	fout << " " << states[node]->m;
}

void bfs(vector<int>* q) {
	vector<int>* nq = new vector<int>();
	vector<int>::iterator iter = q->begin();
	bool ret = false;
	//cout << "Processing vector of size: " << q->size() << endl;
	while (iter != q->end()) {
		int s = *iter;
/*		if (states[s] != NULL ) {
			++iter;
			continue;
		}*/
		
		//state_visited[s] = true;
		for (int i = 0; i < 9; ++i) {
			int v;
			/*if (key_count[i] == 3) continue;
			key_count[i]++; */
			ret = apply_move(s, i, &v);

			if (states[v] == NULL) {
				states[v] = new node;
				states[v]->prev_node = s;
				states[v]->m = i + 1;
				nq->push_back(v);
			}

			if (ret) {
				print_path(v);
				fout << endl;
				break;
			}
		}
		
		if (ret) break;
		
		++iter;
	}

	delete q;
	if (ret || nq->size() == 0) return;
	bfs(nq);
}

int main(int argc, char** argv) {
	int c;
	source_clock = 0;
	for (int i = 0; i < 9; ++i) {
		fin >> c;
		c = (c / 3) % 4;
		source_clock |= (c << (i * 2));
	}

	if (source_clock == 0) return 0;
	
	states[source_clock] = new node;
	states[source_clock]->prev_node = -1;
	
	for (int i = 0; i < 9; ++i) key_count[i] = 0;
	
	vector<int>* q = new vector<int>();
	q->push_back(source_clock);
	bfs(q);
	
	for (int i = 0; i < 300000; ++i) {
		if (states[i] != NULL) delete states[i];
	}
	
	return 0;
}