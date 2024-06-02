#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

vector<int> adj[MxN];
int n, q, sz[MxN], level[MxN], heavy[MxN], head[MxN], parent[MxN], disc[MxN], ps[MxN], timer = 0;

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
	ps[timer] = u;
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

struct segment_tree {
	int tree[MxN << 2];
	void build() {
		memset(tree, 0x3f, sizeof tree);
	}
	void update(int l, int r, int id, int v, int idx) {
		if(l > r || l > id || r < id) {
			return ;
		}
		if(l == r) {
			tree[idx] = (tree[idx] >= 1e9 + 100 ? v: (int) (1e9 + 100));
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, v, idx << 1);
		update(mid + 1, r, id, v, idx << 1 | 1);
		tree[idx] = min(tree[idx << 1], tree[idx << 1 | 1]);
	}
	int query(int l, int r, int wl, int wr, int idx) {
		if(l > r || l > wr || r < wl) {
			return 1e9 + 100;
		}
		if(wl <= l && r <= wr) {
			return tree[idx];
		}
		int mid = (l + r) >> 1;
		return min(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
	}
} seg;

int query(int u) {
	int cur_answer = 1e9 + 100;
	while(head[u] != 0) {
		cur_answer = min(cur_answer, seg.query(1, n, disc[head[u]], disc[u], 1));
		u = parent[head[u]];
	}
	return (cur_answer >= 1e9 + 100 ? -1: ps[cur_answer]);
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=2, u, v; i<=n; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1, 0);
	hld(1, 0);
	seg.build();
	while(q--) {
		int opr, v;
		cin >> opr >> v;
		if(opr == 0) {
			// update
			seg.update(1, n, disc[v], disc[v], 1);
		}
		else {
			// query
			cout << query(v) << "\n";		
		}
	}
	return 0;
}
