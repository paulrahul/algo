#include <set>
#include <set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Egalitarianism {
	private:
		int max_path;
		set<int> touched;
		set<int> path;
		
		void traverse(const vector<string>& isFriend, int u, int len) {
			int num_visited = 0;
			
			for (int i = 0; i < isFriend[u].length(); ++i) {
				if (isFriend[u][i] == 'N') continue;
				
				if (path.find(i) != path.end()) continue;
			
				int v = i;
				touched.insert(v);
				bool valid = true;
				for (int j = 0; j < isFriend[v].length(); ++j) {
					if (j == u) continue;
					
					if (isFriend[v][j] == 'N') continue;
					
					// check if already in path making a cycle.
					if (path.find(j) != path.end()) {
						valid = false;
						break;
					}
				}
				
				if (valid) {
					num_visited++;
					path.insert(v);
					traverse(isFriend, v, len + 1);
				}
			}
			
			if (num_visited == 0) {
				max_path = max(max_path, len);
			}
			
			path.erase(u);
		}

	public:
		int maxDifference(vector <string> isFriend, int d) {
			max_path = -1;
			for (int i = 0; i < isFriend.size(); ++i) {
				path.clear();
				path.insert(i);
				touched.insert(i);
				traverse(isFriend, i, 0);
				
			if (touched.size() != isFriend.size()) {
				cout << touched.size() << endl;
				return -1;
			}				
			}
			

			
			return d * max_path;
		}
};

int main() {
	Egalitarianism obj;
	
	vector<string> friends;
	friends.push_back("NYN");
	friends.push_back("YNY");	
	friends.push_back("NYN");
	
	std::cout << obj.maxDifference(friends, 10);
	
	return 0;
}