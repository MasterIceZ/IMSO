/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Lazy Segment Tree
 * ALGO		: Lazy Segment Tree
 * DATE		: 21 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Lazy_Seg{
	vector<int> tree, lazy;
	int N;
	Lazy_Seg(size_t n){
		tree.resize(4 * n, 0);
		lazy.resize(4 * n, 0);
		N = n;
	}
	void push(int idx){
		tree[idx * 2] += lazy[idx];
		lazy[idx * 2] += lazy[idx];
		tree[idx * 2 + 1] += lazy[idx];
		lazy[idx * 2 + 1] += lazy[idx];
		lazy[idx] = 0;
	}
	void update(int l, int r, int wl, int wr, int val, int now){
		if(l > r || r < wl || l > wr){
			return ;
		}
		if(wl <= l && r <= wr){
			tree[now] += val;
			lazy[now] += val;
			return ;
		}
		push(now);
		int mid = (l + r) >> 1;
		update(l, mid, wl, wr, val, now * 2);
		update(mid + 1, r, wl, wr, val, now * 2 + 1);
		tree[now] = max(tree[now * 2], tree[now * 2 + 1]);
	}
	void update(int wl, int wr, int val){
		update(1, N, wl, wr, val, 1);
	}
	int read(int l, int r, int idx, int now){
		if(l > r || l > idx || r < idx){
			return -1e9 - 10;
		}
		if(l <= idx && idx <= r){
			return tree[now];
		}
		push(now);
		int mid = (l + r) >> 1;
		return max(read(l, mid, idx, now * 2), read(mid + 1, r, idx, now * 2 + 1));
	}
	int read(int idx){
		return read(1, N, idx, 1);
	}
} lzy(300);

void solve(){
	lzy.update(1, 10, 2);
	lzy.update(5, 7, 1);
	for(int i=1; i<=20; ++i){
		cout << lzy.read(i) << " ";
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
