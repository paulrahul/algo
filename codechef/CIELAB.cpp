#include <iostream>
#include <sstream>


using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int diff = a - b;
	
	stringstream ss;
	ss << diff;
	string num = ss.str();
	
	if (num[0] == '1') {
		num[0] = '2';
	} else {
		num[0] = '1';
	}

	cout << num << endl;

	return 0;
}
