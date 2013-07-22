#include <iostream>
#include <vector>

using namespace std;

typedef long long int64;

int64 max;

struct node {
	node() {
		this->l = 0;
		this->b = 0;
		this->color = 0;
	}

	int l;
	int b;
	int color; // 0 white, 1 gray, 2 black
};

void dfs(int index, node[] nodes, int n, vector<int>& bands, int b, int64 sum) {
	int num_visited = 0;
	nodes[index].color = 1; //gray
	for (int i = 0; i < n; ++i) {
		if (i != index && nodes[i].color == 0) {
			num_visited++;
			bands[nodes[i].b]++;
			if (bands[nodes[i].b] == 1) b++; //new band 
			dfs(i, nodes, n, bands, b, sum + nodes[i].l * b);
			bands[nodes[i].b]--;
		}
	}
	if (num_visited == 0) {
		if (sum > max) max = sum;
	}
	
	nodes[index].color = 0; //white.
}

int64 dfs_main(node[] nodes, int n) {
	for (int i = 0; i < n; ++i) {
	
	}
}

int main(int argc, char** argv) {
	int t, n;
	
	cin >> t;
	while(t--) {
		cin >> n;
		max = 0;
	}

	return 0;
}