#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int check_heavy(const string& str, int i) {
	static string heav = "vaeh";

	int j = 0;
	while (j < 4 && i >= 0 && str[i] == heav[j]) {
		i--;
		j++;
	}
	
	return i + 1;
}

int check_metal(const string& str, int i) {
	static string meta = "atem";

	int j = 0;
	while (j < 4 && i >= 0 && str[i] == meta[j]) {
		i--;
		j++;
	}
	
	return i + 1;
}

int main(int argc, char** argv) {
	string str;
	cin >> str;
	
	int metal_count = 0;
	long long count = 0;
	
	int n = str.length() - 1;
	if (n < 9) {
		cout << "0" << endl;
		return 0;
	}

	while (n >= 0) {
		if (str[n] == 'y') {
			int i = check_heavy(str, n - 1);
			if (n - i + 1 == 5) {
				count += metal_count;
			}
			n = i - 1;
			continue;
		}
		
		if (str[n] == 'l') {
			int i = check_metal(str, n - 1);
			if (n - i + 1 == 5) {
				metal_count++;
			}
			
			n = i - 1;
			continue;
		}
	
		n--;
	}
	
	setprecision(20);
	cout << count << endl;

	return 0;
}