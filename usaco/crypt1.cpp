/*
ID: paul.ra1
LANG: C++
TASK: crypt1
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool is_valid(int num, int len, int arr[], int arrlen) {
	int i;
	while (num > 0 && len > 0) {
		int d = num % 10;
		for (i = 0; i < arrlen; ++i) {
			if (d == arr[i]) break;
		}
		
		if (i >= arrlen) {
			return false;
		}
	
		num /= 10;
		len--;
	}
	
	if (num == 0 && len == 0) return true;
	return false;
}

int main(int argc, char** argv) {
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	
	int num;
	fin >> num;
	int arr[9];
	for (int i = 0; i < num; ++i) fin >> arr[i];

	int n1, n2;
	int n1_arr[1000];
	int n2_arr[100];
	
	sort(arr, arr + num);
	// generate 3 digit nums
	int p = 0;
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			for (int k = 0; k < num; ++k) {
				n1_arr[p++] = 100*arr[i] + 10*arr[j] + arr[k];
			}
		}
	}
	int n1len = p;

	// generate 2 digit nums
	p = 0;
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			n2_arr[p++] = 10*arr[i] + arr[j];
		}
	}
	int n2len = p;
	
	int ret = 0;
	for (int i = 0; i < n1len; ++i) {
		for (int j = 0; j < n2len; ++j) {
			int p1 = n1_arr[i] * (n2_arr[j] % 10);
			int p2 = n1_arr[i] * (n2_arr[j] / 10);
			
			if (!is_valid(p1, 3, arr, num)) continue;
			if (!is_valid(p2, 3, arr, num)) continue;
			int p = p2 * 10 + p1;
			if (!is_valid(p, 4, arr, num)) continue;
			// fout << n1_arr[i] << " " << n2_arr[j] << endl;
			ret++;
		}
	}
	
	fout << ret << endl;
	
	return 0;
}