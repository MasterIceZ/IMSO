#include <bits/stdc++.h>

using namespace std;

struct edge_t {
	int u, v, w;
	bool operator < (const edge_t& o) const {
		return w < o.w;
	}
	edge_t(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
};

struct raw_query_t {
	int t, a, b, idx;
	raw_query_t(int _t, int _a, int _b, int _idx):
		t(_t), a(_a), b(_b), idx(_idx) {}
}

struct query_t {
	int a, b, idx;
	query_t(int _a, int _b, int _idx):
		a(_a), b(_b), idx(_idx) {}
};

vector<edge_t> edges;
vector<raw_query_t> raw_query;
vector<query_t> query[MxN];
vector<int> query_times;
int parent[MxN];

int find_root(int u) {
	if(u == parent[u]) {
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i) {
		parent[i] = i;
	}
	for(int i=1; i<=m; ++i) {
		cin >> u >> v >> w;
		edges.emplace_back(++u, ++v, w);
	}
	for(int i=1; i<=q; ++i) {
		cin >> a >> b >> k;
		raw_query.emplace_back(k, a, b, i);
		query_times.emplace_back(k);
	}
	sort(query_times.begin(), query_times.end());
	query_times.resize(unique(query_times.begin(), query_times.end()) - query_times.begin());
	sort(edges.begin(), edges.end());
	for(auto x: edges) {
		int ru = find_root(x.u);
		int rv = find_root(x.v);
		if(ru == rv) {
			continue;
		}

	}
}
