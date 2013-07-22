#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
	int t, n, m;
	int j;

	cin >> t;

	while (t-- > 0) {
		cin >> n >> m;

		bool finished[1001] = {false};
		for (int i = 0; i < m; ++i) {
			cin >> j;
			finished[j] = true;
		}

		stringstream c;
		stringstream a;

		bool chef = true;
		for (int i = 1; i <= n; ++i) {
			if (finished[i])  continue;

			stringstream& s = chef ? c : a;

			s << i << " ";

			chef = !chef;
		}

		string cs = c.str();
		string as = a.str();

		cs = cs.substr(0, cs.length() - 1);
		as = as.substr(0, as.length() - 1);

		cout << cs << endl << as << endl;
	}

	return 0;
}