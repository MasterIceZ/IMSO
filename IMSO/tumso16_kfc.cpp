/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: tumso16_kfc
 * ALGO		: Segment Tree
 * DATE		: 2 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 200200;
ll a[MxN];
ll tree[4 * MxN], lazy[4 * MxN];

void build(int l, int r, int now){
	if(l > r){
		return ;
	}
	if(l == r){
		tree[now] = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, now * 2);
	build(mid + 1, r, now * 2 + 1);
	tree[now] = tree[now * 2] + tree[now * 2 + 1];
}

void lzy(int x){
	if(lazy[x]){
		lazy[x * 2] += lazy[x];
		lazy[x * 2 + 1] += lazy[x];
		tree[x * 2] += lazy[x];
		tree[x * 2 + 1] += lazy[x];
		lazy[x] = 0;
	}
}

void update(int l, int r, int wl, int wr, ll v, int now){
	if(l > r || r < wl || l > wr){
		return ;
	}
	if(wl <= l && r <= wr){
		tree[now] += v;
		lazy[now] += v;
		return ;
	}
	lzy(now);
	int mid = (l + r) >> 1;
	update(l, mid, wl, wr, v, now * 2);
	update(mid + 1, r, wl, wr, v, now * 2 + 1);
	tree[now] = tree[now * 2] + tree[now * 2 + 1];
}

ll read(int l, int r, int wl, int wr, int now){
	if(l > r || r < wl || l > wr){
		return 0;
	}
	dbg(l, r);
	lzy(now);
	if(wl <= l && r <= wr){
		return tree[now];
	}
	lzy(now);
	int mid = (l + r) >> 1;
	ll L = read(l, mid, wl, wr, now * 2);
	ll R = read(mid + 1, r, wl, wr, now * 2 + 1);
	dbg(L, R);
	return L + R;
}

void solve(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i){
		scanf("%lld", &a[i]);
	}
	build(1, n, 1);
	while(m--){
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		if(t == 1){
			ll x;
			scanf("%lld", &x);
			update(1, n, l, r, x, 1);
		}
		else{
			dbg(l, r);
			string now = to_string(read(1, n, l, r, 1));
			dbg(now);
			bool ei = false, fo = false;
			for(auto x: now){
				ei |= (x == '8');
				fo |= (x == '4');
				if(ei && fo){
					break;
				}
			}
			printf("%s\n", (ei && fo ? "YES": "NO"));
		}
	}
	printf("%lld", read(1, n, 1, 2, 1));
	return ;
}

int main(){
	int q = 1;
	while(q--){
		solve();
	}
	return 0;
}
