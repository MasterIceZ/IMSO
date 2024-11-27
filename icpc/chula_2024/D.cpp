#include <bits/stdc++.h>

using namespace std;

struct val_t {
	ll sum, cnt;
	val_t(ll _sum=0ll, ll _cnt=0ll):
		sum(_sum), cnt(_cnt) {}
	friend val_t operator + (const val_t &lhs, const val_t &rhs) {
		return val_t(lhs.sum + rhs.sum, lhs.cnt + rhs.cnt);
	}
};

struct segment_tree {
	struct node_t;
	using pnode_t = node_t *;
	struct node_t {
		val_t val;
		pnode_t l, r;
		node_t():
			val(), l(nullptr), r(nullptr) {}
		node_t(val_t v):
			val(v), l(nullptr), r(nullptr) {}
	};
	pnode_t rt;
	segment_tree(ll n):
		rt(new node_t()) {}
	void update(ll l, ll r, ll idx, val_t v, pnode_t &t) {
		if(!t) {
			t = new node_t();
		}
		t->val += v;
		if(l == r) {
			return ;
		}
		ll mid = (l + r) >> 1ll;
		if(idx <= mid) {
			update(l, mid, idx, v, t->l);
		}
		else {
			update(mid + 1ll, r, idx, v, t->r);
		}
	}
	ll search(ll l, ll r, val_t v, pnode_t &t) {
		if(l == r) {
			return l;
		}
		if(!t) {
			t = new node_t();
		}
		ll mid = (l + r) >> 1ll;
		val_t cur_v(t->l ? t->l->sum: 0ll, t->r ? t->r->cnt: 0ll);
		if(v.sum + cur_v.sum + (mid * (v.cnt + cur_v.cnt)) < mid * k) {
			return search(l, mid, val_t(v.sum, v.cnt + cur_v.cnt), t->l);
		}
		else {
			return search(mid + 1ll, r, val_t(v.sum + cur_v.sum, v.cnt), t->r);
		}
	}
};

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	return 0;
}
