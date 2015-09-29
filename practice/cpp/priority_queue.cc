#include <iostream>
#include <queue>
#include <functional>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <memory>

using namespace std;

struct mytype {
	int key;
	string name;
	
	mytype(int k, string n) {
		this->key = k;
		this->name = n;
	}
};

typedef bool (*comp)(const mytype&, const mytype&);
bool my_comparison(const mytype& a, const mytype& b) {
	return a.key > b.key;
}

int main() {
	priority_queue<int, vector<int>, greater<int> > q1;
	for (int i = 1; i < 10; ++i) {
		q1.push(i);
	}
	
	while (!q1.empty()) {
		cout << q1.top() << ", ";
		q1.pop();
	}
	cout << endl;
	
	priority_queue<mytype, vector<mytype>, comp> q2(my_comparison);
	srand(time(NULL));
	for (int i = 0; i < 10; ++i) {
		int k = rand() % 100;
		q2.push(mytype(k, "blah"));
	}
	
	while (!q2.empty()) {
		cout << q2.top().key << ", ";
		q2.pop();
	}
	cout << endl;
	
	typedef priority_queue<mytype, vector<mytype>, comp> MQ;
	MQ q3(my_comparison);
	srand(time(NULL));
	for (int i = 0; i < 10; ++i) {
		int k = rand() % 100;
		q3.push(mytype(k, "blah"));
	}
	
	while (!q3.empty()) {
		cout << q3.top().key << ", ";
		q3.pop();
	}
	cout << endl;
	
	return 0;
}