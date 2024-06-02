#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

struct segment_tree {
	int t[MxN];
	
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
		t[idx] = min(t[idx << 1], t[idx << 1 | 1]);
	}

	int query(int l, int r, int wl, int wr, int idx) {
		if(l > r || l > wr || r < wl) {
			return 1e9 + 100;
		}
		if(wl <= l && r <= wr) {
			return t[idx];
		}
		int mid = (l + r) >> 1;
		return min(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
	}
};

int n, val[MxN];
vector<int> adj[MxN];

// Block cut tree
stack<int> st;
int bct_timer, disc[MxN], low[MxN], art[MxN];
bitset<MxN> visited, disc_art;
vector<vector<int>> components, t;
vector<int> t_sz;

// HLD
int hld_timer, head[MxN], parent[MxN], disc_hld[MxN], level[MxN], sz[MxN], heavy[MxN];

// Block cut tree
void articulation_point(int u, int p) {
	disc[u] = low[u] = ++bct_timer;
	visited[u] = true;
	st.emplace(u);
	int cnt = 0;
	for(auto x: adj[u]) {
		if(x == p) {
			continue;
		}
		if(disc[x] == 0) {
			articulation_point(x, u);
			low[u] = min(low[u], low[x]);
			cnt++;
			if((p == 0 && cnt > 1) || (p != 0 && low[x] >= disc[u])) {
				art[u] = true;
			}
			if(low[x] >= disc[u]) {
				vector<int> c = {u};
				while(c.back() != x) {
					c.emplace_back(st.top());
					st.pop();
				}
				components.emplace_back(c);
			}
		}
		else {
			low[u] = min(low[u], disc[x]);
		}
	}
}

void build_block_cut_tree() {
	t.emplace_back(vector<int> ());
	t_sz.emplace_back(0);
	for(int i=1; i<=n; ++i) {
		if(!art[i]) {
			continue;
		}
		disc_art[disc[i] = t.size()] = true;
		t.emplace_back(vector<int> ());
		t_sz.emplace_back(1);
	}
	for(auto comp: components) {
		t.emplace_back(vector<int> ());
		t_sz.emplace_back(comp.size());
		for(auto x: comp) {
			if(art[x]) {
				t[disc[x]].emplace_back(t.size() - 1);
				t.back().emplace_back(disc[x]);
			}
			else {
				disc[x] = t.size() - 1;
			}
		}
	}
}

// HLD
void dfs(int u, int p) {
	parent[u] = p;
	sz[u] = 1;
	level[u] = level[p] + 1;
	int cur_heavy = 0, cur_max = 0;
	for(auto x: t[u]) {
		if(x == p) {
			continue;
		}
		dfs(x, u);
		sz[u] += sz[x];
		if(sz[x] > cur_max) {
			cur_max = sz[x];
			cur_heavy = x;
		}
	}
	heavy[u] = cur_heavy;
}

void hld(int u, int p) {
	if(head[u] == 0) {
		head[u] = u;
	}
	disc_hld[u] = ++hld_timer;
	if(heavy[u] != 0) {
		head[heavy[u]] = head[u];
		hld(heavy[u], u);
	}
	for(auto x: t[u]) {
		if(x == p || x == heavy[u]) {
			continue;
		}
		hld(x, u);
	}
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int m, q;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i) {
		cin >> val[i];
	}
	for(int i=1, u, v; i<=m; ++i) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	articulation_point(1, 0);
	build_block_cut_tree();
	dfs(1, 0);
	hld(1, 0);

	return 0;
}
