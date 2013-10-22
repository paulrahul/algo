#include <iostream>
#include <vector>

using namespace std;

struct node {
	node() {
		color = 0;
	}

	int color;
	vector<int> neighbour;
};

bool dfs(vector<node>* g, int idx) {
	node& nd = g->at(idx);

	if (nd.color != 0) {
		return false;
	}
	
	nd.color = 1;

	int nc = nd.neighbour.size();
	for (int i = 0; i < nc; ++i) {
		if (nd.neighbour[i] < idx) {
			continue;
		}
		if (!dfs(g, nd.neighbour[i])) {
			return false;
		}
	}

	nd.color = 2;
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<node> g(n, node());
	int u, v;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		g[u - 1].neighbour.push_back(v - 1);
		g[v - 1].neighbour.push_back(u - 1);
	}	

	bool valid = true;
	for (int i = 0; i < g.size(); ++i) {
		if (g[i].color == 0) {
			if (i > 0  /* unconnected */ ||
					!dfs(&g, i)) {
				valid = false;
				break;
			}
		}
	}

	if (valid) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
};
