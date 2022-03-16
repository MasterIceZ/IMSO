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

struct Lazy_Propagation{
	vector<int> tree;
	vector<bool> lazy;
	size_t n;
	Lazy_Propagation(size_t N){
		n = N;
		tree.resize(4 * N, 0);
		lazy.resize(4 * N, false); 
	}
	void lzy(int idx){
		if(lazy[idx]){
			tree[2 * idx] = tree[2 * idx + 1] = tree[idx];
			lazy[idx] = false;
			lazy[2 * idx] = lazy[2 * idx + 1] = true;
		}
	}
	void update(int l, int r, int wl, int wr, int val, int now){
		if(l > r || wr < l || wl > r){
			return ;
		}
		if(wl <= l && r <= wr){
			tree[now] = val;
			lazy[now] = true;
			return ;
		}
		int mid = (l + r) >> 1;
		lzy(now);
		update(l, mid, wl, wr, val, now * 2);
		update(mid + 1, r, wl, wr, val, now * 2 + 1);
		tree[now] = min(tree[now * 2], tree[now * 2 + 1]);
	}
	void update(int wl, int wr, int val){
		update(1, n, wl, wr, val, 1);
	}
	int read_point(int l, int r, int idx, int now){
		if(l > r || r < idx || l > idx){
			return 1e9 + 10;
		}
		if(l == r){
			return tree[now];
		}
		int mid = (l + r) >> 1;
		lzy(now);
		if(idx <= mid){
			return read_point(l, mid, idx, now * 2);
		}
		return read_point(mid + 1, r, idx, now * 2 + 1);
	}
	int read_point(int idx){
		return read_point(1, n, idx, 1);
	}
	int read_range(int l, int r, int wl, int wr, int now){
		if(l > r || l > wr || r < wl){
			return 1e9 + 10;
		}
		if(wl <= l && r <= wr){
			return tree[now];
		}
		int mid = (l + r) >> 1;
		lzy(now);
		return min(read_range(l, mid, wl, wr, now * 2), read_range(mid + 1, r, wl, wr, now * 2 + 1));
	}
	int read_range(int wl, int wr){
		return read_range(1, n, wl, wr, 1);
	}
} seg(100);

void solve(){
	seg.update(1, 10, 1);
	seg.update(3, 5, 2);
	for(int i=1; i<=11; ++i){
		cout << seg.read_point(i) << "\n";
	}
	seg.update(11, 11, -1);
	cout << seg.read_range(3, 11);
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
