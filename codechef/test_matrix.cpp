#include <iostream>

using namespace std;

int total = 0;
int n, m;

void recurse(int x, int y) {
	if (x == n && y == m) {
		total++;
		return;
	}
	
	if (x > n) return;
	if (y > m) return;
	
	//right
	recurse(x, y + 1);
	//bottom
	recurse(x + 1, y);
}

int main() {
	cin >> n >> m;
	
	total = 0;
	recurse(1, 1);
	cout << total << endl;
	
	return 0;
}