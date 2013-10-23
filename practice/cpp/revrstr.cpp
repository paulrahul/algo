#include <iostream>
#include <string>

using namespace std;

void rev(string* str, int l, int r) {
	for (int i = l, j = r; i < j; ++i, --j) {
		char t = (*str)[i];
		(*str)[i] = (*str)[j];
		(*str)[j] = t;
	}
}

int main() {
	string str;
	getline(cin, str);
	
	// compress the string i.e. reduce spaces to single space
	int r = 0;
	int nspace = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == ' ' && nspace > 0) {
			continue;
		}

		str[r++] = str[i];
		if (str[i] == ' ') {
			++nspace;
		} else {
			nspace = 0;
		}
	}
	str[r++] = '\0';
	while (str[r] != '\0') {
		str[r++] = '\0';
	}

	// Reverse the string now.
	rev(&str, 0, str.length() - 1);

	// Now reverse each word.
	int j = 0;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ' ') {
			rev(&str, j, i - 1);
			j = i + 1;
		}
	}
	cout << str << endl;

	return 0;
}
