#include <string.h>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const int MAX_N = 101;
const int MAX_M = 101;
const int MAX_F = 1000000;

int table[MAX_N][MAX_N];
int status[MAX_M][MAX_N];
int N, M;

typedef unsigned long long ULL;
typedef vector<int> VI;
typedef set<int> SI;

void solve(int k);
ULL point(SI& s);
bool is_finish(SI& s);

ULL maxval = 0;

struct state {
	int p;
	SI s;
};

vector<state> cls;

int main() {
	int u, v, f;
	cls = vector<state>();

	// read data
	cin >> N >> M;
	memset(&table[0][0], 0, sizeof(int) * MAX_N * MAX_N);
	memset(&table[0][0], 0, sizeof(int) * MAX_M * MAX_N);
	for(int m=0; m<M; m++) {
		cin >> u >> v >> f;
		table[u-1][v-1] = f;
		table[v-1][u-1] = f;
		status[m][u-1] = 1;
		status[m][v-1] = 1;
	}

	// solve problem
	maxval = 0;
	for(int i=0; i<M; i++) {
		solve(i);
	}

	// print answer
	cout << maxval << endl;
}

void solve(int k) {
	queue<SI> que;
	
	// set initial node
	SI s = SI();
	for(int i=0; i<N; i++) {
		if(status[k][i]) s.insert(i);
	}
	if(s.size() == 0) return;

	que.push(s);
	while(!que.empty()) {
		SI cs = que.front();
		que.pop();

		if(is_finish(cs)) continue;

		ULL p = point(cs);
		if(maxval < p) maxval = p;
		
		int s = cs.size();
		if(s == N) continue;
		for(int i=0; i<N; i++) {
			bool is_f = true;
			for(SI::const_iterator jt = cs.begin(); jt != cs.end(); ++jt) {
				int u = (*jt);
				if(i != u && table[i][u] == 0) {
					is_f = false;
					break;
				}
			}
			
			if(is_f) {
				SI ns = SI();
				for(SI::const_iterator it = cs.begin(); it != cs.end(); ++it) ns.insert((*it));
				ns.insert(i);
				que.push(ns);
			}
		}
	}
}

ULL point(SI& s) {
	ULL val = 0;
	for(SI::const_iterator it=s.begin(); it != s.end(); ++it) {
		int min_f = MAX_F;
		for(SI::const_iterator jt=s.begin(); jt != s.end(); ++jt) {
			if(it == jt) continue;
			int k = (*it);
			int l = (*jt);
			if(min_f > table[k][l]) min_f = table[k][l];
		}
		val += (ULL)min_f;
	}

	state st;
	st.p = val;
	st.s = s;
	cls.push_back(st);

	return val;
}

bool is_finish(SI& s) {
	int size = cls.size();
	for(int i=0; i<size; i++) {
		SI s0 = cls[i].s;
		if(s.size() != s0.size()) continue;

		SI::const_iterator it = s.begin();
		SI::const_iterator it0 = s0.begin();
		bool is_match = true;
		while(it != s.end() && it0 != s0.end()) {
			if((*it) != (*it0)) {
				is_match = false;
				break;
			}
			++it;
			++it0;
		}
		if(is_match) return true;
	}
	return false;
}