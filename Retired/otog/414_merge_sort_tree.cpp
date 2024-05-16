#include <bits/stdc++.h>

using namespace std;
using node_t = vector<int>;

const int MxN = 50050;

int a[MxN];

struct segment_tree {
	node_t t[MxN << 2];
	
	node_t merge(node_t l, node_t r) {
		node_t res;
		int i = 0, j = 0;
		while(i < (int) l.size() && j < (int) r.size() && (int) res.size() < 10) {
			if(l[i] < r[j]) {
				res.emplace_back(l[i++]);
			}
			else {
				res.emplace_back(r[j++]);
			}
		}
		while(i < (int) l.size() && (int) res.size() < 10) {
			res.emplace_back(l[i++]);
		}
		while(j < (int) r.size() && (int) res.size() < 10) {
			res.emplace_back(r[j++]);
		}
		return res;
	}

	void build(int l, int r, int idx) {
		if(l > r) {
			return ;
		}
		if(l == r) {
			t[idx].emplace_back(a[l]);
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		t[idx] = merge(t[idx << 1], t[idx << 1 | 1]);
	}

	node_t query(int l, int r, int wl, int wr, int idx) {
		if(l > r || l > wr || r < wl) {
			return {};
		}
		if(wl <= l && r <= wr) {
			return t[idx];
		}
		int mid = (l + r) >> 1;
		return merge(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
	}
} seg;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q, l, r;
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	seg.build(1, n, 1);
	while(q--) {
		cin >> l >> r;
		l++, r++;
		for(auto x: seg.query(1, n, l, r, 1)) {
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}
