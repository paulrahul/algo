#include <iostream>

using namespace std;

long long traverse(int triangle[][101], long long max_from[][101], int height, int row, int col) {
	if (row > height || col > height) {
		return 0;
	}

	if (max_from[row][col] != -1) {
		//cout << "returning " << max_from[row][col] << endl;
		return max_from[row][col];
	}

	long long sum1 = traverse(triangle, max_from, height, row + 1, col);
	long long sum2 = traverse(triangle, max_from, height, row + 1, col + 1);

	max_from[row][col] = triangle[row][col];
	max_from[row][col] += (sum1 > sum2) ? sum1 : sum2;

	return max_from[row][col];
}

int main(int argc, char** argv) {
	int t, height;

	cin >> t;
	while (t-- > 0) {
		int triangle[101][101];
		long long max_from[101][101];

		for (int i = 0; i < 101; ++i) {
			for (int j = 0; j < 101; ++j) {
				max_from[i][j] = -1;
			}
		}

		cin >> height;

		for (int i = 1; i <= height; ++i) {
			for (int j = 1; j <= i; ++j) {
				cin >> triangle[i][j];
			}
		}

		long long sum_max = traverse(triangle, max_from, height, 1, 1);

		cout << sum_max << endl;

	}
	return 0;
}