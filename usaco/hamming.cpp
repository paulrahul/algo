/*
ID: paul.ra1
LANG: C++
TASK: hamming
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int n, b, d;

bool isAtleastHD(int a, int b) {
	int c = a ^ b;
	
	int hd = 0;
	while (c) {
		++hd;
		c = c & (c - 1);
	}
	
	return (hd >= d);
}

struct f {
	f() {
	}
	
	f(int idx, int t) {
		this->idx = idx;
		this->t = t;
	}
	
	int idx;
	int t;
};

vector<f> ft;
vector<int> color;
int global_f = 0;
vector<int> curr_ans;
vector<int> ans;

void dfs(const vector<vector<int> >& graph, int u, bool isTrans) {
	color[u] = 1;
	++global_f;
	int access_time = global_f;
	
	int num_adj = graph[u].size();
	for (int i = 0; i < num_adj; ++i) {
		int v = graph[u][i];
		if (color[v] == 0) {
			dfs(graph, v, isTrans);
		}
	}
	
	if (global_f > access_time) ++global_f;

	ft[u] = f(u, global_f);
	color[u] = 2;
	if (isTrans) {
		curr_ans.push_back(u);
	}
}

bool compare_f(const f& a, const f& b) {
	if (a.t == b.t) return (a.idx < b.idx);

	return (a.t > b.t);
}

int main() {
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");

	cin >> n >> b >> d;
	
	int lim = pow(2, b);
	
	// Create the normal and transposed graphs for 1...lim.
	vector<vector<int> > graph(lim, vector<int>());
	vector<vector<int> > trans_graph(lim, vector<int>());
	for (int i = 0; i < lim - 1; ++i) {
		for (int j = i + 1; j < lim; ++j) {
			if (!isAtleastHD(i, j)) continue;
			
			graph[i].push_back(j);
			trans_graph[j].push_back(i);
		}
	}
	
	ft = vector<f>(lim);
	color = vector<int>(lim, 0);
	global_f = 0;

	// Now do DFS on normal graph calculating finishing times.
	for (int i = 0; i < lim; ++i) {
		if (color[i] == 0) {
			dfs(graph, i, false);
		}
	}
	
	sort(ft.begin(), ft.end(), &compare_f);
	
	// Now do DFS on transposed graph in reverse finishing times order.
	color = vector<int>(lim, 0);
	for (int i = 0; i < lim; ++i) {
		int j = ft[i].idx;

		if (color[j] != 0) continue;

		curr_ans.clear();
		dfs(trans_graph, j, true);

		if (curr_ans.size() >= n) {
			sort(curr_ans.begin(), curr_ans.end());

			bool valid = true;
			int k = 0;
			while (k < ans.size()) {
				if (curr_ans[k] > ans[k]) {
					valid = false;
					break;
				}
				k++;
			}
			
			if (valid) ans = curr_ans;
		}			
	}
	
	int len = ans.size();
	for (int i = 1; i <= len; ++i) {
		if (i == len - 1 || (i + 1) % 10 == 0) {
			cout << ans[i - 1] << endl;
		} else {
			cout << ans[i - 1] << " ";		
		}
	}
	
	return 0;
}