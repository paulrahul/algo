#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int val;
	node* next;
	node* prev;
};

node* addNode(int val) {
	node* n = new node;
	n->val = val;
	n->next = n->prev = NULL;
	return n;
}

node* head_;

// Move node i to the position having val < y
void move(int i, int y) {
	node* m = head_;
	int j = 0;
	while (j < i) {
		m = m->next;
		++j;
	}
	m->val = y;
	
	node* t = head_;
	node* prev = NULL;
	while (t && t->val <= y) {
		prev = t;
		t = t->next;
	}
	
	if (m == prev) {
		return;
	}
	
	// Remove m and move it in y's place.
	if (m->prev) m->prev->next = m->next;
	if (m->next) m->next->prev = m->prev;
	if (m == head_) {
		head_ = m->next;
		head_->prev = NULL;
	}
	
	if (prev) {
		m->prev = prev;
		m->next = prev->next;
		prev->next = m;
	} else {
		// must be head_
		m->next = head_;
		m->next->prev = m;
		head_ = m;
	}
}

int main() {
	int n, l, m;
	cin >> n >> l >> m;
	
	int e[n];
	for (int i = 0; i < n; ++i) {
		cin >> e[i];
	}
	sort(e, e + n);

	head_ = addNode(e[0]);
	node* curr = head_;
	for (int i = 1; i < n; ++i) {
		curr->next = addNode(e[i]);
		curr->next->prev = curr;
		curr = curr->next;
	}		
	
	int i, y;
	for (int j = 0; j < m; ++j) {
		cin >> i >> y;
		
		// move the elephant.
		move(i, y);  // O(N)
		
		// iterate through the LL in jumps on l size. O(N)
		int ans = 0;
		curr = head_;
		int begin = curr->val;
		while(curr) {
			begin = curr->val;
			++ans;
			while (curr && curr->val <= begin + l) {
				curr = curr->next;
			}
		}
		
		cout << ans << endl;
	}
	
	// destroy LL
	curr = head_;
	node* next = curr->next;
	while (curr) {
		next = curr->next;
		delete curr;
		curr = next;
	}
	
	return 0;
}