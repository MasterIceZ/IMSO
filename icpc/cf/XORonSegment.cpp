#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxS = 22;
const int MxN = 100010;

ll a[MxN];

struct node_t {
	ll val[MxS];

	void add_value(ll v, ll seg_range) {
		for(ll i=0; i<(ll) MxS; ++i) {
			ll this_bit = (1ll << i);
			if(!(v & this_bit)) {
				continue;
			}
			val[i] = seg_range - val[i];
		}
	}

	ll calculate() {
		ll res = 0ll;
		for(ll i=0ll; i<(ll) MxS; ++i) {
			res += (1ll << i) * val[i];
		}
		return res;
	}

	friend node_t operator + (const node_t &lhs, const node_t &rhs) {
		node_t res;
		for(int i=0; i<MxS; ++i) {
			res.val[i] = lhs.val[i] + rhs.val[i];
		}
		return res;
	}

	node_t() {}
};

struct segment_tree {
	node_t t[MxN << 2];
	int lazy[MxN << 2];

	void build(int l, int r, int idx) {
		if(l > r) {
			return ;
		}
		if(l == r) {
			t[idx].add_value(a[l], 1);
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		t[idx] = t[idx << 1] + t[idx << 1 | 1];
	}

	void push_lazy(int idx, int l, int r) {
		if(!lazy[idx]) {
			return ;
		}
		t[idx].add_value(lazy[idx], r - l + 1);
		if(l != r) {
			lazy[idx << 1] ^= lazy[idx];
			lazy[idx << 1 | 1] ^= lazy[idx];
		}
		lazy[idx] = 0ll;
	}
	
	void update(int l, int r, int wl, int wr, ll v, int idx) {
		push_lazy(idx, l, r);
		if(l > r || l > wr || r < wl) {
			return ;
		}
		if(wl <= l && r <= wr) {
			t[idx].add_value(v, r - l + 1);
			if(l != r) {
				lazy[idx << 1] ^= v;
				lazy[idx << 1 | 1] ^= v;
			}
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, wl, wr, v, idx << 1);
		update(mid + 1, r, wl, wr, v, idx << 1 | 1);
		t[idx] = t[idx << 1] + t[idx << 1 | 1];
	}

	long long query(int l, int r, int wl, int wr, int idx) {
		push_lazy(idx, l, r);
		if(l > r || l > wr || r < wl) {
			return 0ll;
		}
		if(wl <= l && r <= wr) {
			return t[idx].calculate();
		}
		int mid = (l + r) >> 1;
		return query(l, mid, wl, wr, idx << 1) + query(mid + 1, r, wl, wr, idx << 1 | 1);
	}
} seg;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, q;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}	
	seg.build(1, n, 1);
	cin >> q;
	while(q--) {
		int opr;
		cin >> opr;
		if(opr == 1) {
			int l, r;
			cin >> l >> r;
			cout << seg.query(1, n, l, r, 1) << "\n";
		}
		else {
			int l, r;
			ll x;
			cin >> l >> r >> x;
			seg.update(1, n, l, r, x, 1);
		}
	}
	return 0;
}
