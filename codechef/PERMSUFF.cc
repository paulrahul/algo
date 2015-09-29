#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

struct subset {
	int parent;
	int rank;
};

int find(vector<subset>& subsets, int i)
{
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
	}
 
    return subsets[i].parent;
}
 
void unify(vector<subset>& subsets, int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
	}
    else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
	}
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int main() {
	int t, n, m;
	int l, r;
	
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> curr_state(n + 1, 0);
		vector<subset> ss(n + 1, subset());
		for (int i = 1; i <= n; ++i) {
			cin >> curr_state[i];
			ss[i].parent = i;
			ss[i].rank = 0;
		}
		
		for (int i = 0; i < m; ++i) {
			cin >> l >> r;
			
			if (l > r) {
				int tmp = l;
				l = r;
				r = tmp;
			}
			
			for (int j = l; j < r; ++j) {
				unify(ss, j, j + 1);
			}
		}
		
		bool valid = true;
		for (int i = 1; i <= n; ++i) {
			int curr = i;
			int desired = curr_state[i];
			
			if (ss[curr].parent != ss[desired].parent) {
				valid = false;
				break;
			}
		}
		
		if (valid) {
			cout << "Possible";
		} else {
			cout << "Impossible";
		}
		cout << endl;
		
	}
	
	return 0;
}