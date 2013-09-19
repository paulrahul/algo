#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string reduce(int n) {
	if (n == 0) {
		return "0";
	} else if (n == 1) {
		return "";
	}
	
	string ret = "";
	while (n) {
		if (ret != "") {
			ret += "+";
		}

		int p = log2(n);
		
		ret += "2";
		string tmp = reduce(p);
		if (tmp != "") {
			ret += "(" + tmp + ")";
		}
		n = n - pow(2, p);
	}

	return ret;
}

int main() {
	int arr[] = {137, 1315, 73, 136, 255, 1384, 16385};
	int size = 7;
	
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << "=" << reduce(arr[i]) << endl;
	}

	return 0;
}
