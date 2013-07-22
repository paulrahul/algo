#include <iostream>
#include <set>
#include <vector>
#include <utility>

using namespace std;

#define LL long long

vector<vector<pair <int, int> > > po_paths;
vector<vector<pair <int, int> > > mantis_paths;

void traverse_po(int triangle[][501], int height, int row, int col, vector<pair <int, int> > path) {
	if (row > height || row < 1) return;
	if (col > height || col < 1) return;

	path.push_back(make_pair(row, col));

	if (row == height) {
		if (col == 1) {
			po_paths.push_back(path);
		}

		return;
	}

	traverse_po(triangle, height, row + 1, col - 1, path);
	traverse_po(triangle, height, row + 1, col, path);
	traverse_po(triangle, height, row + 1, col + 1, path);
}

void traverse_mantis(int triangle[][501], int height, int row, int col, vector<pair <int, int> > path) {
	if (row > height || row < 1) return;
	if (col > height || col < 1) return;

	path.push_back(make_pair(row, col));

	if (row == height) {
		if (col == 1) {
			mantis_paths.push_back(path);
		}
	}

	traverse_mantis(triangle, height, row - 1, col - 1, path);
	traverse_mantis(triangle, height, row, col - 1, path);
	traverse_mantis(triangle, height, row + 1, col - 1, path);
}

LL sum(const vector<pair <int, int> > po_path, vector<pair <int, int> > mantis_path, int triangle[][501]) {
	LL sum = 0;

	set <pair <int, int> > nodes;

	nodes.insert(po_path.begin(), po_path.end());
	nodes.insert(mantis_path.begin(), mantis_path.end());

	set <pair <int, int> >::iterator it = nodes.begin();
	int r, c;
	while (it != nodes.end()) {
		r = it->first; c = it->second;
		sum += triangle[r][c];
		++it;
	}

	return sum;
}


int main(int argc, char** argv) {
	int t, n;

	cin >> t;
	while (t-- > 0) {
		cin >> n;
		int triangle[501][501];

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				cin >> triangle[i][j];
			}
		}

		vector<pair <int, int> > path;
		traverse_po(triangle, n, 1, 1, path);

		path.clear();
		traverse_mantis(triangle, n, n, n, path);

		int plen = po_paths.size();
		int mlen = mantis_paths.size();
		LL max = -1;
		LL local_sum = 0;
		for (int i = 0 ; i < plen; ++i) {
			for (int j = 0; j < mlen; ++j) {
				local_sum = sum(po_paths[i], mantis_paths[j], triangle);

				if (local_sum > max) {
					max = local_sum;
				}
			}
		}

		cout << max << endl;
	}
	return 0;
}