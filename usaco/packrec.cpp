/*
ID: paul.ra1
LANG: C++
TASK: packrec
*/

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

struct Rect {
	Rect() {
		this->l = 0;
		this->b = 0;
	}

	Rect(int l, int b) {
		this->l = l;
		this->b = b;
	}

	int l, b;
};

struct classcomp {
	bool operator() (const Rect& r1, const Rect& r2) const {
		if (r1.l == r2.l && r1.b == r2.b) return 0;
		if (r1.l != r2.l) return (r1.l < r2.l);
		return (r1.b < r2.b);
	}
};

int min_rect;
set<Rect, classcomp> ans;

void eval_min(int L, int B) {
//	cout << L << " " << B << endl;
	int A = L * B;
	if (A <= min_rect) {
		min_rect = A;
		Rect ar = (L <= B) ? Rect(L, B) : Rect(B, L);
		ans.insert(ar);
	}
}

void a1(Rect r[]) {
	int L = 0;
	int B = 0;
	for (int i = 0; i < 4; ++i) {
		L = max(L, r[i].l);
		B += r[i].b;
	}

	eval_min(L, B);
}

void a2(Rect r[]) {
	int L = 0;
	int B = 0;
	for (int i = 0; i < 3; ++i) {
		L = max(L, r[i].l);
		B += r[i].b;
	}
	
	L = L + r[3].l;
	B = max(B, r[3].b);
	
	eval_min(L, B);
}

void a3(Rect r[]) {
	int L = 0;
	int B = 0;
	for (int i = 0; i < 2; ++i) {
		L = max(L, r[i].l);
		B += r[i].b;
	}
	L = L + r[2].l;
	B = max(B, r[2].b);

	L = max(L, r[3].l);
	B = B + r[3].b;
	
	eval_min(L, B);
}

void a4(Rect r[]) {
	int L = 0;
	int B = 0;

	L = r[0].l;
	B = r[0].b;
	
	L = max(L, r[1].l + r[2].l);
	B = B + max(r[1].b, r[2].b);

	L = max(L, r[3].l);
	B = B + r[3].b;
	
	eval_min(L, B);
}

void a5(Rect r[]) {
	int L = 0;
	int B = 0;

	L = r[0].l + r[1].l;
	B = max(r[0].b, r[1].b);
	
	L = max(L, r[2].l);
	B = B + r[2].b;

	L = max(L, r[3].l);
	B = B + r[3].b;
	
	eval_min(L, B);
}

void a6(Rect r[]) {
	int L = 0;
	int B = 0;

	L = r[0].l + r[1].l;
	B = max(r[0].b, r[1].b);

	B = B + r[2].b;

	L = max(L, r[3].l + r[2].l);
	if (r[2].l >= (r[0].l + r[1].l)) {
		B = max(B, r[3].b);
	}
	else {
		int adj = (r[0].b >= r[1].b) ? 0 : 1;
		
		if (r[2].l < r[adj].l) {
			if  (r[3].b > r[2].b) B = B + (r[3].b - r[2].b);
		} else {
			if (r[3].b > (r[2].b + abs(r[0].b - r[1].b))) B = B + (r[3].b - (r[2].b + abs(r[0].b - r[1].b)));
		}
	}
	
	eval_min(L, B);
}

Rect invert(Rect r) {
	return Rect(r.b, r.l);
}

void evaluate(Rect r[4]) {
	string p[] = {"0000", "0001", "0010", "0011",
				  "0100", "0101", "0110", "0111",
				  "1000", "1001", "1010", "1011",
				  "1100", "1101", "1110", "1111"};

	Rect lr[4];
	for (int i = 0; i < 16; ++i) {
		lr[0] = (p[i][0] == '0') ? r[0] : invert(r[0]);
		lr[1] = (p[i][1] == '0') ? r[1] : invert(r[1]);
		lr[2] = (p[i][2] == '0') ? r[2] : invert(r[2]);
		lr[3] = (p[i][3] == '0') ? r[3] : invert(r[3]);
		
//		cout << p[i] << " " << endl;
//		cout << lr[0].l << "," << lr[0].b << " " << lr[1].l << "," << lr[1].b << " " 
//			 << lr[2].l << "," << lr[2].b << " " << lr[3].l << "," << lr[3].b << endl;
		
		a1(lr);
		a2(lr);
		a3(lr);
		a4(lr);
		a5(lr);
		a6(lr);
	}
}

void perm(Rect r[4]) {
	string p[] = {"1234", "1243", "1324", "1342", "1423", "1432",
				  "2134", "2143", "2314", "2341", "2413", "2431",
				  "3124", "3142", "3214", "3241", "3412", "3421",
				  "4123", "4132", "4213", "4231", "4312", "4321"};

	Rect lr[4];
	for  (int i = 0; i < 24; ++i) {
//		cout << p[i] << " ";
		lr[0] = r[p[i][0] - '1'];
		lr[1] = r[p[i][1] - '1'];
		lr[2] = r[p[i][2] - '1'];
		lr[3] = r[p[i][3] - '1'];
		evaluate(lr);
	}
}

int main(int argc, char** argv) {
	ifstream fin("packrec.in");
	ofstream fout("packrec.out");
	
	int l, b;
	while (fin >> l >> b) {
		Rect r[4];
		r[0] = Rect(l, b);
		
		for (int i = 1; i <= 3; ++i) {
			fin >> l >> b;
			r[i] = Rect(l, b);
		}
		
		min_rect = 999999;
		ans.clear();
		
		perm(r);
		fout << min_rect << endl;

		set<Rect, classcomp>::iterator iter = ans.begin();
		while (iter != ans.end()) {
			if ( (iter->b * iter->l) == min_rect) {
				fout << iter->l << " " << iter->b << endl;
			}
			++iter;
		}
	}
	
	return 0;
}