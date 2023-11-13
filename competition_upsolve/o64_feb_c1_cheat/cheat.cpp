#include <bits/stdc++.h>
#include "cheat.h"

using namespace std;

const int MxN = 200020;

struct disjoint_set {
	pair<int, int> parent[MxN]; // (parent, merge time)
	int sz[MxN];
	int find_root(int u) {
		while(u != parent[u].first) {
			u = parent[u].first;
		}
		return u;
	}
	int find_root_check(int u, int mid) {
		while(parent[u].second != 0 && parent[u].second <= mid) {
			u = parent[u].first;
		}
		return u;
	}
	void unite(int u, int v, int t) {
		int ru = find_root(u);
		int rv = find_root(v);
		if(sz[ru] > sz[rv]) {
			parent[rv] = make_pair(ru, t);
			sz[ru] = sz[ru] + sz[rv];
		}
		else {
			parent[ru] = make_pair(rv, t);
			sz[rv] = sz[rv] + sz[ru];
		}
	}
	disjoint_set() {
		for(int i=1; i<MxN; ++i) {
			parent[i] = make_pair(i, 0);
			sz[i] = 1;
		}
	}
} dsu;

int current_time = 0;

void cheat(int person1, int person2) {
	int root_u = dsu.find_root(person1);
	int root_v = dsu.find_root(person2);
	if(root_u == root_v) {
		return ;
	}
	dsu.unite(root_u, root_v, ++current_time);
}

int investigate(int person1, int person2) {
	int l = 0, r = current_time + 1;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(dsu.find_root_check(person1, mid) == dsu.find_root_check(person2, mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return l == current_time + 1 ? -1: l;
}
