/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o60_oct_c2_tower
 * ALGO		: Lazy Propagation, Segment Tree
 * DATE		: 26 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct SegTree{
	struct Node{
		int a, b, l, r;
		Node(int w, x, y, z): a(w), b(x), l(y), r(z) {}
	};
	vector<Node> tree;
	vector<int> lazy;
	int n;
	void build(int l, int r, int now){
		if(l > r){
			return ;
		}
		tree[now].b = 1;
		if(l == 1){
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, now << 1);
		build(mid + 1, r, now << 1 | 1);
	}
	SegTree(int N){
		tree.resize(4 * N + 10);
		lazy.resize(4 * N + 10);
		n = N;
		build(1, n, 1);
	}
	void update(int l, int r, int wl, int wr, int v, int now){
		if(l > r){
			continue;
		}
		if(lazy[now]){
			tree[now].a += lazy[now];
			tree[now].l += lazy[now];
			tree[now].r += lazy[now];
			if(l != r){
				lazy[now << 1] += lazy[now];
				lazy[now << 1 | 1] += lazy[now];
			}
			lazy[now] = 0;
		}
		if(wr < l || r < wl){
			return ;
		}
		if(wl <= l && r <= wr){
			tree[now].a += v;
			tree[now].l += v;
			tree[now].r += v;
			if(l != r){
				lazy[now << 1] += v;
				lazy[now << 1 | 1] += v;
			}
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, wl, wr, v, now << 1);
		update(mid + 1, r, wl, wr, v, now << 1 | 1);
		tree[now].l = tree[now << 1].l;
		tree[now].r = tree[now << 1 | 1].r;
		if(tree[now << 1].a != tree[now << 1 | 1].a){
			tree[now] = MAXX(tree[now << 1], tree[now << 1 | 1]);
		}	
	}
	void update(int l, int r, int v){
		update(1, n, l, r, v, 1);
	}
};

void solve(){
	int n, m;
	cin >> n >> m;
	SegTree seg(n);
	for(int i=1; i<m; ++i){
		cin >> l >> r >> h;
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
