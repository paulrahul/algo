#include <iostream>
#include <vector>

using namespace std;

struct node {
	int parent;
	int child;
	int rank;
};

int find(int idx, vector<node>& nd) {
	if (nd[idx].parent != idx) {
		nd[idx].parent = find(nd[idx].parent, nd);
	}
	
	return nd[idx].parent;
}

void unify(int x, int y, vector<node>& nd,
		   const vector<int>& s) {
	int xroot = find(x, nd);
	int yroot = find(y, nd);
	
	int child, parent = -1;
	
	// Make the smaller rank child of higher rank.
	if (nd[xroot].rank < nd[yroot].rank) {
		child = xroot;
		parent = yroot;
	} else if (nd[yroot].rank < nd[xroot].rank) {
		child = yroot;
		parent = xroot;
	} else {
		// Both ranks same. Make x child of y.
		child = xroot;
		parent = yroot;
	}
	
	// Check if s[parent] < s[child]. If yes, swap.
	if (s[child] > s[parent]) {
		int tmp = parent;
		parent = child;
		child = tmp;
	}
	
	nd[child].parent = parent;
	nd[nd[child].child].parent = parent;
	nd[parent].child = child;
	if (nd[parent].rank == nd[child].rank) {
		++nd[parent].rank;
	}
}

void relink(int winner, int loser, vector<node>& nd) {
	int wroot = find(winner, nd);
	int lroot = find(loser, nd);
	
	// Make loser child of winner.
	nd[lroot].parent = wroot;
}

int main() {
	int t, n, q;
	
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> s(n + 1, 0);
		vector<node> nd(n + 1, node());
		for (int i = 1; i <= n; ++i) {
			cin >> s[i];
			nd[i].parent = nd[i].child = i;
			nd[i].rank = 0;
		}
		
		cin >> q;
		int qt, x, y;
		for (int i = 0; i < q; ++i) {
			cin >> qt;
			
			if (qt == 0) {
				cin >> x >> y;
				
				// Check if both have same parent.
				if (find(x, nd) == find(y, nd)) {
					cout << "Invalid query!" << endl;
					continue;
				}
				
				if (s[x] == s[y]) {
					// Tie. Nothing more to do.
					continue;
				}
				
				int winner = s[x] > s[y] ? x : y;
				int loser = s[x] > s[y] ? y : x;				
				relink(winner, loser, nd);
			} else {
				cin >> x;
				cout << find(x, nd) << endl;
			}
		}
	}
	
	return 0;
}