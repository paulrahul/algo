#include <iostream>

using namespace std;

long long sum_max = 0;

void traverse(int triangle[][101], long long max_from[][101], int height, int row, int col, long long sum) {
	if (max_from[row][col] != 0) {
		 cout << row << ", " << col << " : " << max_from[row][col] << endl;
		sum += max_from[row][col];
		if (sum > sum_max) {
			sum_max = sum;
		}
		return;
	}

	int sum_so_far = sum;

	sum += triangle[row][col];
	if (row == height) {
		if (sum > sum_max) {
			sum_max = sum;
		}

		return;
	}

	traverse(triangle, max_from, height, row + 1, col, sum);

	if (col < height) {
		traverse(triangle, max_from, height, row + 1, col + 1, sum);
	}

	cout << row << ", " << col << endl;
	cout << "sum_so_far: " << sum_so_far << ", " << sum_max << endl;
	max_from[row][col] = sum_max - sum_so_far;
}

int main(int argc, char** argv) {
	int t, height;

	cin >> t;
	while (t-- > 0) {
		int triangle[101][101];
		long long max_from[101][101] = {-1};
		cin >> height;

		for (int i = 1; i <= height; ++i) {
			for (int j = 1; j <= i; ++j) {
				cin >> triangle[i][j];
			}
		}

		sum_max = 0;
		traverse(triangle, max_from, height, 1, 1, 0);

		cout << sum_max << endl;
	}

	return 0;
}