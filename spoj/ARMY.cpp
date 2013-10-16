#include <iostream>

using namespace std;

int main() {
	int t, ng, nm;

	cin >> t;
	while (t--) {
		cin >> ng >> nm;

		int mg = -1;
		int mm = -1;
		int tmp = 0;

		for (int i = 0; i < ng; ++i) {
			cin >> tmp;
			mg = max(mg, tmp);
		}

		for (int i = 0; i < nm; ++i) {
			cin >> tmp;
			mm = max(mm, tmp);
		}

		if (mg > mm) {
			cout << "Godzilla" << endl;
		} else if (mm > mg) {
			cout << "MechaGodzilla" << endl;
		} else {
			cout << "Godzilla" << endl;
		}
	}

	return 0;
}
