#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

#define INF 99999

struct node {
	node() {
		this->color = 0;  // black
		this->d = INF;
	}
	int color;
	int d;
};


void bfs(int graph[][101], node nd[], int s, int v, int f) {
	nd[v].color = 1;  // grey
	for (int i = 1; i <= f; ++i) {
		if (graph[v][i] == 1 && nd[i].color == 0) {
			nd[i].d = nd[v].d + 1;
		}
	}

	for (int i = 1; i <= f; ++i) {
		if (i != v && graph[v][i] == 1 && nd[i].color == 0) {
			bfs(graph, nd, s, i, f); 
		}
	}

	nd[v].color = 2; // black
}

void bfs_main(int graph[][101], node nd[], int s, int f) {
	bfs(graph, nd, 1, 1, f);
}

int main(int argc, char** argv) {
	int g, f;
	string line, num;

	getline(cin, num);
	stringstream gss(num);
	gss >> g;

	while (g-- > 0) {
		getline(cin, num);
		stringstream fss(num);
		fss >> f;

		int graph[101][101];
		for (int i = 1; i <= f; ++i) {
			for (int j = 1; j <= f; ++j) {
				if (i == j) graph[i][j] = 0;
				else graph[i][j] = INF;				
			}
		}

		int j;
		for (int i = 1; i <= f; ++i) {
			getline(cin, line);

			// break into numbers
			stringstream ss(line);
			while (getline(ss, num, ' ')) {
				stringstream nss(num);
				nss >> j;
				graph[i][j] = 1;
			}
		}

		// Compute average and find min
		int min_sum = INF;
		int popular = 0;
		for (int i = 1; i <= f; ++i) {
			node nd[f+1];
			bfs_main(graph, nd, i, f);

			int sum = 0;
			for (int j = 1; j <= f; ++j) {
				//cout << graph[i][j] << ",";
				if (i != j && nd[j].d != INF) sum += nd[j].d;
			}
			//cout << endl;

			if (sum < min_sum) {
				min_sum = sum;
				popular = i;
			}
		}


		double min_avg = (double)min_sum / f;

		cout << popular << " " << setprecision(7) << min_avg << endl;
	}

	return 0;
}
