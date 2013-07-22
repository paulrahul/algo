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

vector<int> color;
vector<int> ans;

bool dfs(const vector<vector<int> >& graph,
		 const vector<vector<bool> >& compatible,
		 int u, int len) {
	color[u] = 1;

	// check compatibility with all other nodes in the path.
	for (int j = 0; j < ans.size(); ++j) {
		if (!compatible[u][ans[j]]) {
			color[u] = 0;  // should be revisited from another path
			return false;
		}
	}
	
	ans.push_back(u);
	len++;	
	if (len == n) {
		return true;
	}
	
	int num_adj = graph[u].size();
	for (int i = 0; i < num_adj; ++i) {
		int v = graph[u][i];
		if (color[v] == 0) {
			bool ret = dfs(graph, compatible, v, len);
			if (ret) {
				return ret;
			}
		}
	}
	
	ans.pop_back();
	color[u] = 0;
	return false;
}

int main() {
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");

	fin >> n >> b >> d;
	
	int lim = pow(2, b);
	
	// Create the normal and transposed graphs for 1...lim.
	vector<vector<int> > graph(lim, vector<int>());
	vector<vector<bool> > compatible(lim, vector<bool>(lim, false));
	for (int i = 0; i < lim - 1; ++i) {
		for (int j = i + 1; j < lim; ++j) {
			bool c = isAtleastHD(i, j);
			compatible[i][j] = compatible[j][i] = c;
			if (!c) continue;
			
			graph[i].push_back(j);
			graph[j].push_back(i);
		}
	}
	
	// Run normal DFS
	color = vector<int>(lim, 0);
	for (int i = 0; i < lim; ++i) {
		if (color[i] == 0) {
			bool ret = dfs(graph, compatible, i, 0);
			if (ret) {
				break;
			}
		}
	}
	
	sort(ans.begin(), ans.end());
	int len = ans.size();
	for (int i = 1; i < len; ++i) {
		if (i % 10 == 0) {
			fout << ans[i - 1] << endl;
		} else {
			fout << ans[i - 1] << " ";		
		}
	}
	fout << ans[len - 1] << endl;
	
	return 0;
}
