#include <iostream>

using namespace std;

#define ll int
#define sz (sizeof(ll) * 8)

bool reset(ll bs[], int b) {
	int index = b / sz;
	int bp = b % sz;

	ll mask = (1 << bp);
	bs[index] ^= mask;
	
	return (bs[index] & mask);
}

void closeall(ll bs[], int n) {
	for (int i = 0; i < n; ++i) bs[i] = 0;
}

int main(int argc, char** argv) {
	int n, k;
	cin >> n >> k;
	
	int len = n / sz + 1;
	ll bs[len];
	
	int open_count = 0;
	string str;
	int b;
	closeall(bs, len);
	for (int i = 0; i < k; ++i) {
		cin >> str;
		
		if (str == "CLOSEALL") {
			closeall(bs, len);
			open_count = 0;
		} else {
			cin >> b;
			bool ret = reset(bs, b - 1);
			if (ret) open_count++;
			else open_count--;
		}
		cout << open_count << endl;	
	}

	return 0;
}