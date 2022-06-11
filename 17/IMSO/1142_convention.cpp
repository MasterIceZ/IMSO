/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: convention
 * ALGO		: Segment Tree, Lazy propagation
 * DATE		: 25 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Tree{
	vector<int> tree, lazy;
	int n;
	Tree(size_t _n){
		n = _n;
		tree.resize(4 * n, 0);
		lazy.resize(4 * n, 0);
	}

	void lzy(int now){
		if(lazy[now]){
			tree[now * 2] += lazy[now];
			tree[now * 2 + 1] += lazy[now];
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
			lazy[now] = 0;
		}
	}

	void update(int l, int r, int wl, int wr, int val, int now){
		if(l > r || wl > r || wr < l){
			return ;
		}
		if(wl <= l && r <= wr){
			tree[now] += val;
			lazy[now] += val;
			return ;
		}
		lzy(now);
		int mid = (l + r) >> 1;
		update(l, mid, wl, wr, val, now * 2);
		update(mid + 1, r, wl, wr, val, now * 2 + 1);
		tree[now] = max(tree[now * 2], tree[now * 2 + 1]);
	}
	void update(int wl, int wr, int val=1){
		update(1, n, wl, wr, val, 1); 
	}
	int read(int l, int r, int wl, int wr, int now){
		if(l > r || wr < l || wl > r){
			return -1e9 - 100;
		}
		if(wl <= l && r <= wr){
			return tree[now];
		}
		lzy(now);
		int mid = (l + r) >> 1;
		return max(read(l, mid, wl, wr, now * 2), read(mid + 1, r, wl, wr, now * 2 + 1));
	}
	int read(int wl, int wr){
		return read(1, n, wl, wr, 1);
	}
} seg(200000);

void solve(){
	int n, k;
	cin >> n >> k;
	map<int, int> mp;
	vector<pair<int, int>> qry;
	for(int i=1, a, b; i<=n; ++i){
		cin >> a >> b;
		mp[a] = 1;
		mp[b] = 1;
		qry.emplace_back(a, b);
	}
	int it = 0;
	for(auto x: mp){
		mp[x.first] = ++it;
	}
	for(auto x: qry){
		int a = mp[x.first];
		int b = mp[x.second];
		dbg(a, b);
		if(seg.read(a, b) >= k){
			cout << "no";
		}
		else{
			cout << "yes";
			seg.update(a, b);
		}
		cout << "\n";
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
