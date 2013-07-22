#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node {
	node() {
		this->color = 0;
	}
	int color;
};

long dfs(int index, const map<int, vector<int> >& graph, node* emp) {
	int num_connected = 0;

	emp[index].color = 1; // grey

	if (graph.find(index) != graph.end()) {
		const vector<int>& neighbours = graph.at(index);
		for (int i = 0; i < neighbours.size(); ++i) {
			if (emp[neighbours[i]].color == 0) {
				num_connected += dfs(neighbours[i], graph, emp);
			}
		}
	}

	emp[index].color = 2; //black

	return num_connected + 1;
}

void dfs_main(int n, const map<int, vector<int> >& graph, node* emp,
			  int* num_groups, long long* num_ways) {
	for(int i = 1; i <= n; ++i) {
		if (emp[i].color == 0) {
			(*num_groups)++;
			(*num_ways) *= (dfs(i, graph, emp)) % 1000000007;
		}
	}
}

int main(int argc, char** argv) {
	int t, n, m, a, b;

	cin >> t;

	while (t-- > 0) {
		cin >> n >> m;

		node emp[100001];
		map<int, vector<int> > graph;

		for (int i = 0; i < m; ++i){
			cin >> a >> b;
			graph[a].push_back(b);
		}
		int num_groups = 0;
		long long num_ways = 1;
		dfs_main(n, graph, emp, &num_groups, &num_ways);

		cout << num_groups << " " << num_ways << endl;
	}

	return 0;
}