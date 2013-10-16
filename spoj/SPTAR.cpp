#include <iostream>

using namespace std;

int main() {
	int n;
	int arr[2000];

	cin >> n;
	while (n != 0) {
		arr[0] = 0;
		int head = 0;
		int tmp;

		bool valid = true;
		for (int i = 0, j = 1; i < n; ++i, ++j) {
			cin >> tmp;
		
			if (tmp == j) continue;

			// "Pop" the arr elements till they match current index.
			while (head > 0 && arr[head] == j) {
				--head;
				++j;
			}

			if (head > 0 && tmp > arr[head]) {
				valid = false;
			}

			arr[++head] = tmp;
			--j;
		}

		if (valid) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}

		cin >> n;
	}

	return 0;
}
