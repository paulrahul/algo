// Codechef December 2013 Long: MARBLEGF
// Segment Tree algo. 
// Create - O(N)
// Modify, Lookup - O(lgN)

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

struct nd {
	int b;
	int e;
	ll s;
};

// O(N) operation.
ll create(const vector<int>& arr, vector<nd>& sums, int idx, int b, int e) {
	if (b > e) {
		return 0;
	}

	sums[idx].b = b;
	sums[idx].e = e;
	sums[idx].s = 0;

	if (b == e) {
		sums[idx].s = arr[b];
	} else {
		ll lft = create(arr, sums, 2 * idx, b, (b + e) / 2);
		ll rgt = create(arr, sums, 2 * idx + 1, (b + e) / 2 + 1, e);
		sums[idx].s = lft + rgt;
	}
	return sums[idx].s;
}

// O(lgN) operation.
void add(vector<nd>& sums, int node, int idx, int val) {
	sums[node].s += val;	

	if (sums[node].b == sums[node].e && sums[node].b == idx) {
		return;
	}

	int b = sums[node].b;
	int e = sums[node].e;
	int half = (b + e) / 2;

	if (idx <= half) {
		add(sums, 2 * node, idx, val);
	} else {
		add(sums, 2 * node + 1, idx, val);
	}
}

// O(lgN) operation.
ll get(vector<nd>& sums, int idx, int b, int e) {
	if (b  > e) {
		return 0;
	}

	if (sums[idx].b == b && sums[idx].e == e) {
		return sums[idx].s;
	} 

	int node_b = sums[idx].b;
	int node_e = sums[idx].e;
	int node_half = (node_b + node_e) / 2;	

	if (e <= node_half) {
		return get(sums, 2 * idx, b, e);
	} else if (b >= node_half + 1) {
		return get(sums, 2 * idx + 1, b, e);	
	} else {
		ll lft = get(sums, 2 * idx, b, node_half);
		ll rgt = get(sums, 2 * idx + 1, node_half + 1, e);
		//cout << lft << " " << rgt << endl;
		return lft + rgt;
	}
}

int main() {
	int n, q;

	cin >> n >> q;

	int sz = 2 * pow(2, ceil(log2(n)));

	vector<nd> sums(sz + 1, nd());
	vector<int> arr(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	// Create segment tree.
	create(arr, sums, 1, 1, n);

	char op;
	int i, j;

	for (int x = 0; x < q; ++x) {
		cin >> op >> i >> j;
		++i;

		if (op == 'S') {
			++j;
			cout << get(sums, 1, i, j) << endl;
		} else if (op == 'G') {
			add(sums, 1, i, j);
		} else if (op == 'T') {
			add(sums, 1, i, -j);
		}
	}

	return 0;
}