#include <bits/stdc++.h>

using namespace std;

const int MxN = 330;
const int MxM = 5050;

struct segment_tree {
	int t[MxM << 2], lazy[MxM << 2];
	
	void push_lazy(int l, int r, int idx) {
		if(lazy[idx] == 0 || l == r) {
			return ;
		}
		lazy[idx << 1] = lazy[idx << 1 | 1] = lazy[idx];
		t[idx << 1] = t[idx << 1 | 1] = lazy[idx];
		lazy[idx] = 0;
	}

	void update_range(int l, int r, int wl, int wr, int v, int idx) {
		if(l > r || l > wr || r < wl) {
			return ;
		}
		push_lazy(l, r, idx);
		if(wl <= l && r <= wr) {
			t[idx] = v;
			lazy[idx] = v;
			return ;
		}
		int mid = (l + r) >> 1;
		update_range(l, mid, wl, wr, v, idx << 1);
		update_range(mid + 1, r, wl, wr, v, idx << 1 | 1);
		t[idx] = min(t[idx << 1], t[idx << 1 | 1]);
	}

	int query_range(int l, int r, int wl, int wr, int idx) {
		if(l > r || l > wr || r < wl) {
			return INT_MAX;
		}
		push_lazy(l, r, idx);
		if(wl <= l && r <= wr) {
			return t[idx];
		}
		int mid = (l + r) >> 1;
		return min(query_range(l, mid, wl, wr, idx << 1), query_range(mid + 1, r, wl, wr, idx << 1 | 1));
	}
} seg[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, q, opr, x, y, v;
	cin >> n >> m >> q;
	while(q--) {
		cin >> opr;
		if(opr == 1) {
			cin >> x >> y >> v;
			seg[x].update_range(1, m, y, y, v, 1);
		}
		else if(opr == 2) {
			cin >> x >> v;
			seg[x].update_range(1, m, 1, m, v, 1);
		}
		else if(opr == 3) {
			cin >> x >> y;
			cout << seg[x].query_range(1, m, y, y, 1) << "\n";
		}
		else {
			int answer = INT_MAX;
			for(int i=1; i<=n; ++i) {
				answer = min(answer, seg[i].query_range(1, m, 1, m, 1));
			}
			cout << answer << "\n";
		}
	}
	return 0;
}
