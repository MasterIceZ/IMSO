#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

struct node_t;
using pnode_t = node_t *;

struct node_t {
	int v;
	pnode_t l, r;
	node_t(int _v):
		v(_v), l(nullptr), r(nullptr) {}
};

namespace persist_segtree {
	void build(int l, int r, pnode_t &cur) {
		cur = new node_t(0);
		if(l == r) {
			cur->v = 0;
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, cur->l);
		update(mid + 1, r, cur->r);
		cur->v = cur->l->v + cur->r->v;
	}
	
	void update(int l, int r, int id, int v, pnode_t &cur, pnode_t pre) {
		cur = new pnode_t(*pre);
		if(l == r) {
			cur->v += v;
			return ;
		}
		int mid = (l + r) >> 1;
		if(id <= mid) {
			update(l, mid, id, v, cur->l, pre->l);
		}
		else {
			update(mid + 1, r, id, v, cur->r, pre->r);
		}
		cur->v = cur->l->v + cur->r->v;
	}
}

struct fenwick_tree {
	int t[MxN];
	
	void update(int idx, int v) {
		for(; idx<MxN; idx+=idx&-idx) {
			t[idx] += v;
		}
	}

	int query(int idx) {
		int res = 0;
		for(; idx>0; idx-=idx&-idx) {
			res += t[idx];
		}
		return res;
	}
};

fenwick_tree fw;
pnode_t roots[MxN];
vector<int> adj[MxN];
int tin[MxN], tout[MxN], ps[MxN], timer = 0, subtree_size[MxN], heavy[MxN];

void euler_tour(int u, int p) {
	tin[u] = ++timer;
	ps[timer] = u;
	subtree_size[u] = 1;
	for(auto x: adj[u]) {
		if(x == p) {
			continue;
		}
		euler_tour(x, u);
		subtree_size[u] += subtree_size[x];
		if(sz[x] > sz[heavy[u]]) {
			heavy[u] = x;
		}
	}
	tout[u] = timer;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	int n, q, root;
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> p;
		if(p == 0) {
			root = i;
			continue;
		}
		adj[i].emplace_back(p);
		adj[p].emplace_back(i);
	}

	euler_tour(root, 0);
	persist_segtree::build(1, n, roots[0]);

	return 0;
}
