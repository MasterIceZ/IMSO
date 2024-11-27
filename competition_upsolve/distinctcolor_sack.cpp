#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

struct counter_t {
	int cnt[MxN], unique = 0;
	void insert(int x) {
		if(++cnt[x] == 1) {
			unique++;
		}
	}
	void erase(int x) {
		if(--cnt[x] == 0) {
			unique--;
		}
	}
	int query() {
		return unique;
	}
} c;

vector<int> adj[MxN];
int color[MxN], answer[MxN];
int sz[MxN], tin[MxN], tout[MxN], rev_tin[MxN], heavy[MxN], timer;

void dfs_sz(int u, int p) {
	sz[u] = 1;
	tin[u] = ++timer;
	rev_tin[timer] = u;
	for(auto v: adj[u]) {
		if(v == p) {
			continue;
		}
		dfs_sz(v, u);
		sz[u] += sz[v];
		if(sz[v] > sz[heavy[u]]) {
			heavy[u] = v;
		}
	}
	tout[u] = timer;
}

void sack(int u, int p, bool deleting) {
	for(auto v: adj[u]) {
		if(v == p || v == heavy[u]) {
			continue;
		}
		sack(v, u, true);
	}
	if(heavy[u]) {
		sack(heavy[u], u, false);
	}
	c.insert(color[u]);
	cerr << "U: " << u << "\n";
	for(auto v: adj[u]) {
		if(v == p || v == heavy[u]) {
			continue;
		}
		for(int t=tin[v]; t<=tout[v]; ++t) {
			int adding_vertex = rev_tin[t];
			c.insert(color[adding_vertex]);
			cerr << "INSERTING: " << adding_vertex << "\n";
		}
	}
	answer[u] = c.query();
	if(deleting) {
		for(int t=tin[u]; t<=tout[u]; ++t) {
			int removing_vertex = rev_tin[t];
			c.erase(color[removing_vertex]);
			cerr << "REMOVING: " << removing_vertex << "\n";
		}
	}
	cerr << "DS: ";
	for(int i=1; i<=3; ++i) {
		cerr << c.cnt[i] << " ";
	}
	cerr << "\n";
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	vector<int> compress;
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> color[i];
		compress.emplace_back(color[i]);
	}
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	sort(compress.begin(), compress.end());
	compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
	for(int i=1; i<=n; ++i) {
		color[i] = upper_bound(compress.begin(), compress.end(), color[i]) - compress.begin();
	}
	dfs_sz(1, 0);
	sack(1, 0, false);
	for(int i=1; i<=n; ++i) {
		cout << answer[i] << " ";
	}
	cout << "\n";
	return 0;
}
