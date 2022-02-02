/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o62_oct_c2_power
 * ALGO		: Segment Tree
 * DATE		: 1 Feb 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 200020;

int n, q;

struct SegTree{
	ll tree[4 * MxN];
	bool mi = false;
	SegTree(bool x=false): mi(x) {}
	void build(int l=1, int r=n, int idx=1){
		if(l > r){
			return ;
		}
		if(l == r){
			tree[idx] = l * (mi ? 1: -1);
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]);
	}
	void update(int l, int r, int id, ll v, int idx){
		if(l > r || l > id || r < id){
			return ;
		}
		if(l == r){
			tree[idx] = max(tree[idx], v);
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, id, v, idx << 1);
		update(mid + 1, r, id, v, idx << 1 | 1);
		tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]);
	}
	void update(int idx, ll v){
		update(1, n, idx, v, 1);
	}
	ll read(int l, int r, int wl, int wr, int idx){
		if(l > r || l > wr || r < wl){
			return -1e9 - 10000;
		}
		if(wl <= l && r <= wr){
			return tree[idx];
		}
		int mid = (l + r) >> 1;
		return max(read(l, mid, wl, wr, idx << 1), read(mid + 1, r, wl, wr, idx << 1 | 1));
	}
	ll read(int l, int r){
		return read(1, n, l, r, 1);
	}
} seg1, seg2(true);

void solve(){
	cin >> n >> q;
	seg1.build();
	seg2.build();
	int a, b;
	ll c, res = -1e9 - 100;
	while(q--){
		cin >> a >> b >> c;
		ll x = max(seg1.read(1, a) - a, seg2.read(a, n) + a) + c;
		ll y = max(seg1.read(1, b) - b, seg2.read(a, n) + b) + c;
		res = max({res, x, y});
		cout << res << "\n";
		seg1.update(a, y + a);
		seg1.update(b, x + b);
		seg2.update(a, y - a);
		seg2.update(b, x - b);
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
