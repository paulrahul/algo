// Codechef: GERALD03
// Good question and nicely worked out :). Although took a long long time.
// Greedy solution. O(N)

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

struct ivl {
	int l;
	int r;
};

struct mv {
	mv (int num, string move) {
		this->num = num;
		this->move = move;
	}
	int num;
	string move;
};

int main() {
	int t, n;
	
	cin >> t;
	while (t--) {
		cin >> n;
		vector<ivl> arr(n, ivl());
		for (int i = 0; i < n; ++i) {
			cin >> arr[i].l >> arr[i].r;
		}
		
		vector<mv> moves;
		ll ans = 0;
		for (int i = 1; i < n; ++i) {
			if (arr[i - 1].l < arr[i].l) {
				// For L to go forward, we need to ensure it does not go past
				// or equal to R. So, go till R - 1 at max.
				int num = min(arr[i].l - arr[i - 1].l,
							  arr[i - 1].r - 1 - arr[i - 1].l);
				arr[i - 1].l += num;
				moves.push_back(mv(num, "L+"));
				ans += num;
			} else if (arr[i - 1].l > arr[i].l) {
				// For L to go backward, it can go back as much as it needs
				// since L is always < R to begin with and going back will
				// just make it lesser and never equal to R.
				moves.push_back(mv(arr[i - 1].l - arr[i].l, "L-"));
				ans += arr[i - 1].l - arr[i].l;
				arr[i - 1].l = arr[i].l;
			}
			
			if (arr[i - 1].l < arr[i].l) {
				// That means L could not have been moved more forward as it
				// would touch R. So now, move R foward and L forward
				// alternately.
				int num = min(arr[i].r - arr[i - 1].r,
							  arr[i].l - arr[i - 1].l);				
				moves.push_back(mv(num, "R+L+"));
				ans += 2 * num;
				arr[i - 1].l += num;
				arr[i - 1].r += num;
				
				// Now move L forward if any more gap remaining. It is
				// guaranteed to not cross R at this stage.
				moves.push_back(mv(arr[i].l - arr[i - 1].l, "L+"));
				ans += arr[i].l - arr[i - 1].l;
				arr[i - 1].l = arr[i].l;
				
				// Now move R forward if any more gap remaining. It is
				// guaranteed to not cross R at this stage.
				moves.push_back(mv(arr[i].r - arr[i - 1].r, "R+"));
				ans += arr[i].r - arr[i - 1].r;
				arr[i - 1].r = arr[i].r;				
			}

			// At this point, L would have become same as the next one's. Need
			// to check if R is also same or not. If not, then change R
			// accordingly.
			if (arr[i - 1].r < arr[i].r) {
				moves.push_back(mv(arr[i].r - arr[i - 1].r, "R+"));
				ans += arr[i].r - arr[i - 1].r;
			} else if (arr[i - 1].r > arr[i].r) {
				moves.push_back(mv(arr[i - 1].r - arr[i].r, "R-"));
				ans += arr[i - 1].r - arr[i].r;
			}
			arr[i - 1].r = arr[i].r;
		}
		
		cout << ans << endl;
		int len = moves.size();
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < moves[i].num; ++j) {
				cout << moves[i].move;
			}
		}
		cout << endl;
	}
	
	return 0;
}