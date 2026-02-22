#include <algorithm>
#include <iostream>
#include <vector>

const int MxN = 200020;
const int INF = 1e9 + 100;

struct segment_tree {
	int t[MxN << 2];
	
	void build(int l, int r, int idx, int *a) {
		if(l > r) {
			return ;
		}
		if(l == r) {
			t[idx] = a[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1, a);
		build(mid + 1, r, idx << 1 | 1, a);
		t[idx] = std::min(t[idx << 1], t[idx << 1 | 1]);
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
		t[idx] = std::min(t[idx << 1], t[idx << 1 | 1]);
	}

	int query(int l, int r, int wl, int wr, int idx) {
		if(l > r || l > wr || r < wl) {
			return INF;
		}
		if(wl <= l && r <= wr) {
			return t[idx];
		}
		int mid = (l + r) >> 1;
		return std::min(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
	}
} seg;

int a[MxN];

inline void solve() {
	int n, q;
	std::cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		std::cin >> a[i];
	}
	seg.build(1, n, 1, a);
	while(q--) {
		int o;
		std::cin >> o;
		if(o == 1) {
			int id, v;
			std::cin >> id >> v;
			seg.update(1, n, id, v, 1);
		}
		else {
			int l, r;
			std::cin >> l >> r;
			int sl = 0, sr = r - l;
			while(sl < sr) {
				int smid = (sl + sr) >> 1;
				if(seg.query(1, n, l, l + smid, 1) <= smid) {
					sr = smid;
				}
				else {
					sl = smid + 1;
				}
			}
			std::cout << (seg.query(1, n, l, l + sl, 1) == sl) << "\n";
		}
	}
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
