// https://judge.yosupo.jp/problem/unionfind
#include <bits/stdc++.h>

using namespace std;

template<size_t S>
struct union_by_size {
	vector<int> parent, sz;

	// find root of component
	int find_root(int u) {
		while(u != parent[u]) {
			u = parent[u];
		}
		return u;
	}

	// merge u with v
	bool unite(int u, int v) {
		int ru = find_root(u), rv = find_root(v);
		if(ru == rv) {
			return false;
		}
		if(sz[ru] > sz[rv]) {
			sz[ru] += sz[rv];
			parent[rv] = ru;
		}
		else {
			sz[rv] += sz[ru];
			parent[ru] = rv;
		}
		return true;
	}

	// constructor
	union_by_size() {
		parent = vector<int> (S);
		sz = vector<int> (S, 1);
		for(int i=0; i<(int) S; ++i) {
			parent[i] = i;
		}
	}
};

union_by_size<200020> dsu;

signed main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q, t, u, v;
	cin >> n >> q;
	while(q--) {
		cin >> t >> u >> v;
		if(t == 0) {
			dsu.unite(u, v);
		}
		else {
			cout << (dsu.find_root(u) == dsu.find_root(v)) << "\n";
		}
	}
	return 0;
}
