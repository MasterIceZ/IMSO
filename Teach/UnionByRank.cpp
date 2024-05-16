// https://judge.yosupo.jp/problem/unionfind
#include <bits/stdc++.h>

using namespace std;

template<size_t S>
struct union_by_rank {
	vector<int> parent, rnk;

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
		if(rnk[ru] > rnk[rv]) {
			rnk[ru] = max(rnk[ru], rnk[rv] + 1);
			parent[rv] = ru;
		}
		else {
			rnk[rv] = max(rnk[rv], rnk[ru] + 1);
			parent[ru] = rv;
		}
		return true;
	}

	// constructor
	union_by_rank() {
		parent = vector<int> (S);
		rnk = vector<int> (S, 0);
		for(int i=0; i<(int) S; ++i) {
			parent[i] = i;
		}
	}
};

union_by_rank<200020> dsu;

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
