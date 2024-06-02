#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

struct segment_tree {
	int t[1 << 19];
	
	void build(int l, int r, int idx) {
		if(l > r) {
			return ;
		}
		if(l == r) {
			t[idx] = -1e9 - 100;
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		t[idx] = max(t[idx << 1], t[idx << 1 | 1]);
	}

	void update(int l, int r, int id, int v, int idx) {
		if(l > r || l > id || r < id) {
			return ;
		}
		if(l == r) {
			t[idx] = v;
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, v, idx << 1);
		update(mid + 1, r, id, v, idx << 1 | 1);
		t[idx] = max(t[idx << 1], t[idx << 1 | 1]);
	}

	int query(int l, int r, int wl, int wr, int idx) {
		if(l > r || l > wr || r < wl) {
			return -1e9 - 100;
		}
		if(wl <= l && r <= wr) {
			return t[idx];
		}
		int mid = (l + r) >> 1;
		return max(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
	}
};

vector<int> adj[MxN];
int sz[MxN], level[MxN], heavy[MxN], disc[MxN], parent[MxN], head[MxN], timer;
int v[MxN], n, q;
segment_tree seg;

void dfs(int u, int p) {
	sz[u] = 1;
	level[u] = level[p] + 1;
	parent[u] = p;
	int cur_heavy = 0, cur_max = 0;
	for(auto x: adj[u]) {
		if(x == p) {
			continue;
		}
		dfs(x, u);
		sz[u] += sz[x];
		if(cur_max < sz[x]) {
			cur_heavy = x;
			cur_max = sz[x];
		}
	}
	heavy[u] = cur_heavy;
}

void hld(int u, int p) {
	if(head[u] == 0) {
		head[u] = u;
	}
	disc[u] = ++timer;
	seg.update(1, n, disc[u], v[u], 1);
	if(heavy[u] != 0) {
		head[heavy[u]] = head[u];
		hld(heavy[u], u);
	}
	for(auto x: adj[u]) {
		if(x == p || x == heavy[u]) {
			continue;
		}
		hld(x, u);
	}
}

int query_hld(int u, int v) {
	int cur_answer = -1e9 - 100;
	while(head[u] != head[v]) {
		if(level[head[u]] < level[head[v]]) {
			swap(u, v);
		}
		cur_answer = max(cur_answer, seg.query(1, n, disc[head[u]], disc[u], 1));
		u = parent[head[u]];
	}
	if(level[u] > level[v]) {
		swap(u, v);
	}
	cur_answer = max(cur_answer, seg.query(1, n, disc[u], disc[v], 1));
	return cur_answer;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> v[i];
	}
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	dfs(1, 0);
	hld(1, 0);

	while(q--) {
		int opr, a, b;
		cin >> opr >> a >> b;
		if(opr == 1) {
			seg.update(1, n, disc[a], b, 1);
		}
		else {
			cout << query_hld(a, b) << " ";
		}
	}

	cout << "\n";

	return 0;
}
