/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Lazy_Segtree{
	vector<int> tree;
	vector<bool> lazy;
	size_t n;
	Lazy_Segtree(size_t N){
		n = N;
		tree.resize(4 * n, 0);
		lazy.resize(4 * n, 0);
	}
	void lzy(int idx){
		if(lazy[idx]){
			tree[idx * 2] = tree[idx];
			tree[idx * 2 + 1] = tree[idx];
			lazy[idx * 2 + 1] = lazy[idx];
			lazy[idx * 2] = lazy[idx];
			lazy[idx] = 0;
		}
	}
	void update(int l, int r, int wl, int wr, int val, int now){
		if(l > r || r < wl || l > wr){
			return ;
		}
		if(wl <= l && r <= wr){
			tree[now] = val;
			lazy[now] = true;
			return ;
		}
		lzy(now);
		int mid = (l + r) >> 1;
		update(l, mid, wl, wr, val, now * 2);
		update(mid + 1, r, wl, wr, val, now * 2 + 1);
		tree[now] = max(tree[now * 2], tree[now * 2 + 1]);
	}
	void update(int wl, int wr, int val){
		update(1, n, wl, wr, val, 1);
	}
	int read_range(int l, int r, int wl, int wr, int now){
		if(l > r || r < wl || l > wr){
			return -1e9 - 10;
		}
		if(wl <= l && r <= wr){
			return tree[now];
		}
		lzy(now);
		int mid = (l + r) >> 1;
		return max(read(l, mid, wl, wr, now * 2), read(mid + 1, r, wl, wr, now * 2 + 1));
	}
	int read_range(int wl, int wr){
		return read_range(1, n, wl, wr, 1);
	}
	int read_point(int idx){
		return read_range(1, n, idx, idx, 1);
	}
};

void solve(){

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
