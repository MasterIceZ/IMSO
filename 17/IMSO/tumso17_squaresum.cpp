/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: tumso17_squaresum
 * ALGO		: Lazy Propagation, Segment Tree
 * DATE		: 3 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MOD = 1e9 + 7;
const int MxN = 50500;
int a[MxN];

struct SegTree{
	struct Node{
		ll a, b;
	};
	ll M_modd(ll a, ll b){
		return (a * b) % MOD;
	}
	
	ll P_modd(ll a, ll b){
		return (a + b) % MOD;
	}

	ll x;
	Node tree[4 * MxN];
	ll lazy[4 * MxN];
	
	void build(int l, int r, int now){	
		if(l > r){
			return ;
		}
		if(l == r){
			cin >> x;
			tree[now].a = x;
			tree[now].b = M_modd(x, x);
		}
		int mid = (l + r) >> 1;
		build(l, mid, now * 2);
		build(mid + 1, r, now * 2 + 1);
		tree[now].a = P_modd(tree[now * 2].a, tree[now * 2 + 1].a);
		tree[now].b = P_modd(tree[now * 2].b, tree[now * 2 + 1].b);
	}
	
	void lzy(int now, int l, int r){
		if(lazy[now]){
			tree[now].a = P_modd(tree[now].a, M_modd(lazy[now], (ll)r - (ll)l + 1ll));
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
			lazy[now] = 0;
		}
	}

	void update(int l, int r, int wl, int wr, int v, int now){
		if(l > r){
			return ;
		}
		lzy(now, l, r);
		if(l > wr || r < wl){
			return ;
		}
		if(wl <= l && r <= wr){
			lazy[now] += v;
			lzy(now, l, r);
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, wl, wr, v, now * 2);
		update(mid + 1, r, wl, wr, v, now * 2 + 1);
		tree[now].a = P_modd(tree[now * 2].a, tree[now * 2 + 1].a);
		tree[now].b = P_modd(tree[now * 2].b, tree[now * 2 + 1].b);
	}
	Node read(int l, int r, int wl, int wr, int now){
		if(l > r){
			return Node{0, 0};
		}
		lzy(now, l, r);
		if(l > wr || r < wl){
			return Node{0, 0};
		}
		if(wl <= l && r <= wr){
			return tree[now];
		}
		int mid = (l + r) >> 1;
		Node L = read(l, mid, wl, wr, now * 2);
		Node R = read(mid + 1, r, wl, wr, now * 2 + 1);
		Node CURRENT = Node{0, 0};
		CURRENT.a = P_modd(L.a, R.a);
		CURRENT.b = P_modd(L.b, R.b);
		return CURRENT;
	}

} seg;

void solve(){
	int n, m;
	cin >> n >> m;
	seg.build(1, n, 1);
	while(m--){
		int x, l, r, v;
		cin >> x >> l >> r;
		if(x == 1){
			cin >> v;
			seg.update(1, n, l, r, v, 1);
		}
		else{
			cout << seg.read(1, n, l, r, 1).b << "\n";
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
