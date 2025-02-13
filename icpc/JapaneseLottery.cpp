#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;
const int MxW = 22;

struct node_t {
	int *to;
	node_t() {
		to = (int *) calloc(MxW, sizeof (int));
	}
	void init_node() {
		for(int i=1; i<MxW; ++i) {
			to[i] = i;
		}
	}
};

struct segment_tree {
	node_t t[MxN << 1];
	node_t merge_node(node_t l, node_t r) {
		node_t res;
		for(int i=1; i<MxW; ++i) {
			res.to[i] = l.to[r.to[i]];
		}
		return res;
	}
	void build(int l, int r, int idx) {
		if(l > r) {
			return ;
		}
		if(l == r) {
			t[idx].init_node();
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		t[idx] = merge_node(t[idx << 1], t[idx << 1 | 1]);
	}
	void update(int l, int r, int id, node_t v, int idx) {
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
		t[idx] = merge_node(t[idx << 1], t[idx << 1 | 1]);
	}
};

segment_tree seg;
bitset<MxW> visited;
bitset<MxN> have;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int w, h, q;
	cin >> w >> h >> q;
	seg.build(1, h, 1);
	while(q--) {
		int y, x1, x2;
		cin >> y >> x1 >> x2;
		node_t to_update;
		to_update.init_node();
		if(!have[y]) {
			to_update.to[x1] = x2;
			to_update.to[x2] = x1;
		}
		seg.update(1, h, y, to_update, 1);
		have[y] = !have[y];
		int removing = w;
		visited = 0;
		for(int i=1; i<=w; ++i) {
			int u = i;
			while(!visited[u]) {
				visited[u] = true;
				u = seg.t[1].to[u];
			}
			removing--;
		}
		cout << removing << "\n";
	}
	return 0;
}
