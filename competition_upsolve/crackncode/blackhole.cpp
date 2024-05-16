#include <bit/stdc++.h>

using namespace std;

const int MxK = 770;
const int MxN = 1010;

int dp[MxK][MxN];

struct disjoint_set {
	int parent[MxN];
	void init(int n) {
		for(int i=1; i<=n; ++i) {
			parent[i] = i;
			sz[i] = 1;	
		}
	}
	int find_root(int u) {
		while(u != parent[u]) {
			u = parent[u];
		}
		return u;
	}
	void unite(int u, int v) {
		int ru = find_root(u);
		int rv = find_root(v);
		if(ru == rv) {
			return ;
		}
		if(sz[ru] > sz[rv]) {
			swap(ru, rv);
		}
		sz[rv] += sz[ru];
		parent[ru] = rv;	
	}
	int get_sz(int u) {
		return sz[find_root(u)];
	}
} dsu;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	int n, m, k, answer = 0;
	cin >> n >> m >> k;

	auto process_input = [&]() {
		int e;
		cin >> e;
		dsu.init();
		for(int i=1, u, v; i<=e; ++i) {
			cin >> u >> v;
			dsu.unite(u, v);
		}
	};

	process_input();

	for(int i=1; i<=n; ++i) {
		if(dsu.find_root(1) == dsu.find_root(i)) {
			dp[0][i] = dsu.get_sz[i];
		}
		answer = max(answer, dp[0][i]);
	}

	for(int _=2; _<=m; ++_) {
		process_input();
		for(int i=1; i<=
	}

	return 0;
}
