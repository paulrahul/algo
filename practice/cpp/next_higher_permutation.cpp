#include <iostream>
#include <string>

using namespace std;

string next_perm(string num) {
	int len = num.length();
	
	// Scan from right to left of the input string till we get to a point
	// where the right digit is more than the left digit. -- 0(N)
	int i = len - 2;
	while (i >= 0 && num[i + 1] < num[i]) {
		--i;
	}
	
	if (i < 0) {  // No higher permutation is possible.
		return num;
	}
	
	// Now i stores the index where the replacement should come. The replacement
	// will be the lowest digit to the right of i such it is greater than
	// num[i].  --- O(N)
	int j = i;
	while (j + 1 < len && num[j + 1] > num[i]) {
		++j;
	}
	
	
	// Now num[j] should come to index i. All digits starting from len - 1 to
	// j + 1 are guaranteed to be in ascending order and less than num[i].
	// After that, comes num[i]. After that, will come the digits from j - 1
	// till i + 1 as they will be in ascending order and more than num[i].
	// So if we do the following, then we straight away get the next higher
	// permutation without the need for sorting (thus achieving in O(N)):-
	// 0. Copy over num[0] till num[i - 1] to the return string as is.
	// 1. Put num[j] in index i of answer string.
	// 2. Put digits len - 1 till j + 1 after index i.
	// 3. Put digit num[i] in the next index.
	// 4. Put digits num[j - 1] till num[i + 1] in the next indexes.
	// Resultant string is the answer. --- O(N)
	//
	// Alternative approach:
	// Find i and j as before.
	// Swap num[i] and num[j]
	// Sort the digits from i + 1 to len - 1.  --- O(NlogN)
	
	// Create answer string first as a copy of the input string.
	string ans(num);
	
	// Step 0 is implicitly done as part of the copy constructor.
	
	// Step 1.
	ans[i] = num[j];
	
	// Step 2.
	int nx = i + 1;
	for (int k = len - 1; k > j; k--, nx++) {
		ans[nx] = num[k];
	}
	
	// Step 3.
	ans[nx++] = num[i];
	
	// Step 4.
	for (int k = j - 1; k > i; k--, nx++) {
		ans[nx] = num[k];
	}
	
	return ans;
}


int main() {
	string n;
	
	while (cin >> n) {
		cout << n << " -> " << next_perm(n) << endl;
	}
	
	// cin >> n;
	// string ans = next_perm(n);
	// cout << ans << endl;
	// while (ans != n) {
	// 	n = ans;
	// 	ans = next_perm(n);
	// 	cout << ans << endl;
	// }
	
	return 0;
}