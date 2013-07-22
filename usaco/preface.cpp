/*
 ID: paul.ra1
 LANG: C++
 TASK: preface
 */

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int k[] = { 1, 5, 10, 50, 100, 500, 1000 };
vector<int> keys(k, k + 7);
map<int, string> code;
map<char, int> char_count;

bool isTenPower(const string& x) {
	if (x.length() != 1)
		return false;
	return x == "i" || x == "x" || x == "c" || x == "m";
}

void addCount(const string& str, int num_times) {
//	for (int i = 0; i < num_times; ++i) {
//		cout << str;
//	}
	for (int i = 0; i < str.length(); ++i) {
		char_count[str[i]] += num_times;
	}
}

int useNextCode(int key_index, int remaining) {
	if (code.find(remaining) != code.end()) {
		addCount(code[remaining], 1);
		return 0;
	}

	// Find the key to use now.
	while (keys[key_index] > remaining) {
		key_index--;
	}

	string c = code[keys[key_index]];
	int k = keys[key_index];
	int num_times_used = 1;
	if (isTenPower(c)) {
		num_times_used = remaining / k;
		num_times_used = (num_times_used > 3) ? 3 : num_times_used;
		remaining = remaining - (num_times_used * k);
	} else {
		remaining -= k;
	}

	addCount(c, num_times_used);
	return remaining;
}

void addToMap(int k, string val) {
	if (code.find(k) != code.end()) {
		return;
	}

	code[k] = val;
}

int main() {
	ifstream cin("preface.in");
	ofstream cout("preface.out");
	int n;
	cin >> n;

	code[1] = "i";
	code[5] = "v";
	code[10] = "x";
	code[50] = "l";
	code[100] = "c";
	code[500] = "d";
	code[1000] = "m";

	// Now add the compounds to the matrix.
	int i = 0;
	for (i = 0; i < keys.size() - 2; ++i) {
		if (!isTenPower(code[keys[i]]))
			continue;
		addToMap(keys[i + 1] - keys[i], code[keys[i]] + code[keys[i + 1]]);
		addToMap(keys[i + 2] - keys[i], code[keys[i]] + code[keys[i + 2]]);
	}
	addToMap(keys[i + 1] - keys[i], code[keys[i]] + code[keys[i + 1]]);

	map<int, string>::iterator it = code.begin();
	while (it != code.end()) {
		if (it->second.length() > 1) {
			keys.push_back(it->first);
		}
		it++;
	}

	sort(keys.begin(), keys.end());

	/*for (int i = 0; i < keys.size(); ++i) {
	 cout << keys[i] << " " << code[keys[i]] << endl;
	 }*/

	char_count['i'] = char_count['v'] = char_count['x'] = char_count['l'] = 0;
	char_count['c'] = char_count['d'] = char_count['m'] = 0;

	for (int i = 1; i <= n; ++i) {
		int next_code = keys.size() - 1;
		int remaining = i;

		//cout << i << " = ";
		while (1) {
			remaining = useNextCode(next_code, remaining);
			if (remaining <= 0)
				break;
		}
		//cout << endl;
	}

	map<int, string>::iterator iter = code.begin();
	while (iter != code.end()) {
		string c = iter->second;
		iter++;
		if (c.length() != 1)
			continue;
		if (char_count[c[0]] == 0)
			continue;
		cout << (char) ('A' + (c[0] - 'a')) << " " << char_count[c[0]] << endl;
	}

	return 0;
}
