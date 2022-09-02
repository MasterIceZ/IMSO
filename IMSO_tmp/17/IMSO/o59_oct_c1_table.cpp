/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o59_oct_c1_table
 * ALGO		: Lazy Propagation, Segment Tree
 * DATE		: 18 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int tree[4 * 300 * 5000];
bitset<4 * 300 * 5000> lazy;

void lzy(int idx){
	if(lazy[idx]){
		tree[2 * idx] = tree[2 * idx + 1] = tree[idx];
		lazy[2 * idx] = tree[2 * idx + 1] = true;
		lazy[idx] = false;
	}
}

void update(int l, int r, int wl, int wr, int val, int now){
	if(l > r || wl > r || wr < l){
		return ;	
	}
	if(wl <= l && r <= wr){
		tree[now] = val;
		lazy[now] = true;
		return ;
	}
	lzy(now);
	int mid = (l + r) >> 1;
	update(l, mid,  wl, wr, val, now * 2);
	update(mid + 1, r, wl, wr, val, now * 2 + 1);
	tree[now] = min(tree[now * 2], tree[now * 2 + 1]);
}

int read(int l, int r, int wl, int wr, int now){
	if(l > r || wl > r || wr < l){
		return 1e9 + 10;
	}
	if(wl <= l && r <= wr){
		return tree[now];
	}
	lzy(now);
	int mid = (l + r) >> 1;
	return min(read(l, mid, wl, wr, now * 2), read(mid + 1, r, wl, wr, now * 2 + 1));
}

int point(int l, int r, int idx, int now){
	if(l > r || r < idx || l > idx){
		return 1e9 + 10;
	}
	if(l == r){
		return tree[now];
	}
	lzy(now);
	int mid = (l + r) >> 1;
	if(idx <= mid){
		return point(l, mid, idx, now * 2);
	}
	return point(mid + 1, r, idx, now * 2+ 1);
}

void solve(){
	int n, m, q, opr;
	cin >> n >> m >> q;
	while(q--){
		cin >> opr;
		if(opr == 1){
			cin >> x >> y;
			update();
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
		cout << "\n";
	}
	return 0;
}
