#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>

using namespace std;

vector<bool> v(10, false);
vector<int> previous(10, -1);

void bfs(const int dest, int dist, vector<int> neighbours,
        const vector<vector<int> >& g,
		const map<int, pair<int, int> >& m) {
	vector<int> new_neighbours;
	int sz = neighbours.size();
	
	int mn = -1;
	for (int i = 0; i < sz; ++i) {
		v[i] = true;
		int s = neighbours[i];
		
		for (int j = 0; j < 10; ++j) {
			if (!v[j] && g[s][j] == 1) {
				previous[j] = i;
				if (j == dest) {
					return;
				}
				new_neighbours.push_back(j);
			}
		}
	}
	
	bfs(dest, dist + 1, new_neighbours, g, m);
}

int main() {
	string str;
	cin >> str;
	
	int len = str.length();
	vector<vector<int> > g(10, vector<int>(10, -1));
	map<int, pair<int, int> > m;
	
	for (int i = 0; i < 10; ++i) {
		g[i][i] = 1;
	}

	for (int i = 0; i < len; ++i) {
		if (i > 0) {
			int s = str[i] - '0'; int e = str[i - 1] - '0';
			g[s][e] = 1;
			m[10 * s + e] = make_pair(i, i - 1);
		}
		if (i < len - 1) {
			int s = str[i] - '0'; int e = str[i + 1] - '0';
			m[10 * s + e] = make_pair(i, i + 1);
		}
	}

	int source = str[0] - '0';
	int dest = str[len - 1] - '0';
	
	vector<int> neighbours;
	neighbours.push_back(source);
	previous[source] = source;
	
	if (dest != source) {
		bfs(dest, 0, neighbours, g, m);		
	}
	
	int ans = 0;
	int curr = dest;
	int pre = previous[dest];
	do {
		 
		
	} while (pre != source);
	
	return 0;
}