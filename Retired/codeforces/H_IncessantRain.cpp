#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

struct node_t {
	int sum, pref, suff, maxx;
	node_t(): {}
	node_t(int _sum, int _pref, int _suff, int _maxx):
		sum(_sum), pref(_pref), suff(_suff), max(_maxx) {}
};

struct segment_tree {
	node_t *t;
	segment_tree(int n) {
		int loc_n = n + 1;
		t = (node_t *) calloc(loc_n, sizeof(node_t));
	}
	node_t merge_node(node_t l, node_t r) {
		return node_t(
			l.sum + r.sum,
			std::max(l.pref, r.pref + l.sum),
			std::max(r.suff, l.suff + r.sum),
			std::max({l.maxx, r.maxx, r.pref + l.suff, 0})
		);
	}
	void build(int l, int r, int idx) {
		if(l > r) {
			return ;
		}
		if(l == r) {
			t[idx] = node_t(-1, 0, 0, 0);
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		t[idx] = merge_node(t[idx << 1], t[idx << 1 | 1]);
	}
	void update(int l, int r, int id, node_t new_val, int idx) {
		if(l > r || l > id || r < id) {
			return ;
		}
		if(l == r) {
			t[idx] = new_val;
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, new_val, idx << 1);
		update(mid + 1, r, id, new_val, idx << 1 | 1);
		t[idx] = merge_node(t[idx << 1], t[idx << 1 | 1]);
	}
	node_t query() {
		return t[1];
	}
};

int a[MxN];
std::vector<std::pair<int, int>> updating[MxN];

inline void solve() {
	int n, q;
	std::cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		std::cin >> a[i];
	}
	for(int i=1; i<=n; ++i) {
		updating[i].clear();
	}
	for(int i=1; i<=n; ++i) {
		updating[a[i]].emplace_back(0, i);
	}
	for(int i=1, idx, v; i<=q; ++i) {
		std::cin >> idx >> v;
		updating[a[idx]].emplace_back(i, -idx);
		a[idx] = v;
		updating[a[idx]].emplace_back(i, idx);
	}
	segment_tree seg(n);
	seg.build(1, n, 1);
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
