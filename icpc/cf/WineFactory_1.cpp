#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 500050;

struct node_t {
	ll a, b;
	node_t(ll _a = 0ll, ll _b = 0ll):
		a(_a), b(_b) {}
	friend node_t operator + (node_t l, node_t r) {
		return node_t(l.a + r.a - min(l.a, r.b), l.b + r.b - min(l.a, r.b));
	}
};

struct segment_tree {
	node_t t[MxN << 2];
	inline static node_t make_node(ll a, ll b) {
		if(a - b > 0) {
			return node_t(a - b, 0);
		}
		return node_t(0, b - a);
	}
	void build(int l, int r, int idx, ll *v) {
		if(l > r) {
			return ;
		}
		if(l == r) {
			t[idx] = ;
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		t[idx] = t[idx << 1] + t[idx << 1 | 1];
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
		t[idx] = t[idx << 1] + t[idx << 1 | 1];
	}
};

ll a[MxN], b[MxN], c[MxN];

auto main(int argc, char *argv[]) -> signed {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i) {
		cin >> b[i];
	}
	for(int i=1; i<n; ++i) {
		cin >> c[i];
	}
	for(int i=1; i<=n; ++i) {

	}
	seg.build(1, n, 1, diff_arr);
	ll sum = accumulate(b + 1, b + n + 1, 0ll);
	while(q--) {
		int pos;
		cin >> pos;
		sum -= b[pos];
		ll x, y, z;
		cin >> x >> y >> z;
		b[pos] = y;
		sum += y;
		seg.update(1, n, pos, seg::make_node(a[pos], b[pos]), 1);
	}
	return 0;
}
