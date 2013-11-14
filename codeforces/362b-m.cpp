#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
	vector<bool> d(n + 1, false);
	vector<int> di(m, -1);
	int tmp;
	bool valid = true;
	for (int i = 0; i < m; ++i) {
		cin >> tmp;
		d[tmp] = true;
		di[i] = tmp;
	}
	
	if (d[1] || d[n]) {
		valid = false;
	} else {
		for (int i = 0; i < m; ++i) {
			int idx = di[i];
			if (idx > 1 && idx < n && d[idx - 1] && d[idx + 1]) {
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
}