#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <sstream>

using namespace std;

class BoredPhilosophers {
	public:
		vector<int> simulate(vector<string> text, int N) {
			stringstream ss;
			for (int i = 0; i < text.size(); ++i) {
				ss << text[i];
			}

			text.clear();
			string token;
			while (getline(ss, token, ' ')) {
				text.push_back(token);
			}

			int index[3000];
			
			map<string, int> word_map;
			int next_ind = 1;
			for (int i = 0; i < text.size(); ++i) {
				if (word_map.find(text[i]) != word_map.end()) {
					index[i] = word_map[text[i]];
				} else {
					index[i] = next_ind;
					word_map[text[i]] = next_ind;
					next_ind++;
				}
			}
			
			vector<int> ret;
			ret.push_back(word_map.size());
			
			int bigl = text.size();
			for (int i = 2; i <= N; ++i) {
				set<vector<int> > seqs;
				int len = i;
				
				int num = 0;
				for (int j = 0; j <= bigl - len; ++j) {
					vector<int> local;
					for (int k = 0; k < len; ++k) {
						local.push_back(index[j+k]);
					}
					
					if (seqs.find(local) == seqs.end()) {
						num++;
						seqs.insert(local);
					}
				} 	
				
				ret.push_back(num);
			}
			
			return ret;
		}
};

int main(int argc, char** argv) {
	BoredPhilosophers b;

	vector<string> text;
	text.push_back("aaa bbb aaa bbb aaa aaa");

	vector<int> ret = b.simulate(text, 4);
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << ", ";
	}
	cout << endl;

	return 0;
}