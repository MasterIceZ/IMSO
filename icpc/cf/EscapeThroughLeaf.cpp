#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010; 

struct line_t {
	ll m, c;
	ll operator() (ll x) {
		return m * x + c;
	}
	line_t(ll _m=0ll, ll _c=1e18 + 100ll):
		m(_m), c(_c) {}
};

struct LCT {
	line_t t[MxN << 2];
	void add_line(int l, int r, line_t line, int idx) {
		int mid = (l + r) >> 1;
		if(line(mid) > t[idx](mid)) {
			swap(line, t[idx]);
		}
		if(line(l) > t[idx](l)) {
			add_line(l, mid, line, idx << 1);
		}
		if(line(r) > t[idx](r)) {
			add_line(mid + 1, r, line, idx << 1 | 1);
		}
	}
	ll query(int l, int r, ll x, int idx) {
		if(l == r) {
			return t[idx](x);
		}
		int mid = (l + r) >> 1;
		return max({t[idx](x), query(l, mid, x, idx << 1), query(mid + 1, r, x, idx << 1 | 1)});
	}
} lct;

ll a[MxN], b[MxN];
vector<int> adj[MxN];
int level[MxN], sz[MxN], parent[MxN], tin[MxN], tout[MxN], pos[MxN], head[MxN], timer;

void dfs_sz(int u, int p) {
	sz[u] = 1;
	level[u] = level[p] + 1;
	parent[u] = p;
	tin[u] = ++timer;
	pos[timer] = u;
	int cur_heavy = 0, cur_max = 0;
	for(auto v: adj[u]) {
		if(v == p) {
			continue;
		}
		dfs_sz(v, u);
		sz[u] += sz[v];
		if(cur_max < sz[v]) {
			cur_heavy = v;
			cur_max = sz[v];
		}
	}
	heavy[u] = cur_heavy;
	tout[u] = timer;
}

void dfs_hld(int u, int p) {
	if(head[u] == 0) {
		head[u] = u;
	}
	if(heavy[u] != 0) {
		head[heavy[u]] = head[u];
		dfs_hld(heavy[u], u);
	}
	for(auto v: adj[u]) {
		if(v == p || v == heavy[u]) {
			continue;
		}
		dfs_hld(x, u);
	}
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i) {
		cin >> b[i];
	}
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs_sz(1, 0);
	dfs_hld(1, 0);
	return 0;
}
