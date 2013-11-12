#include <iostream>
#include <map>

using namespace std;

struct seq {
	int mn;
	int mx;
};

int main() {
	int t, n;
	
	cin >> t;
	while (t--) {
		cin >> n;
	
		map<int, seq> data;
		int tmp;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
		
			bool mx_found = (data.find(tmp + 1) != data.end()) ? true : false;
			bool mn_found = (data.find(tmp - 1) != data.end()) ? true : false;
		
			if (!mx_found && !mn_found) {
				data[tmp].mn = data[tmp].mx = tmp;
			} else if (mx_found && !mn_found) {
				// Update max's borders too.
				data[tmp].mn = tmp;
				data[tmp].mx = data[tmp + 1].mx;
				data[tmp + 1].mn = tmp;
			} else if (!mx_found && mn_found) {
				// Update min's borders too.
				data[tmp].mn = data[tmp - 1].mn;
				data[tmp].mx = tmp;
				data[tmp - 1].mx = tmp;			
			} else {
				// Found both min and max sides.
				data[tmp].mn = data[tmp - 1].mn;
				data[tmp].mx = data[tmp + 1].mx;
			}
		}
	
		int mx = 0;
		int mn = 0;
		map<int, seq>::iterator iter = data.begin();
		while (iter != data.end()) {
			if (iter->second.mx - iter->second.mn > mx - mn) {
				mx = iter->second.mx;
				mn = iter->second.mn;
			}
			++iter;
		}
	
		cout << mn << " " << mx << endl;
	}
		
	return 0;
}
