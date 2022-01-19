/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: light
 * ALGO		: Fenwick Tree
 * DATE		: 7 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;

vector<int> c;

struct LazySeg{
	bool lazy[4 * MxN];
	int tree[4 * MxN];
	void push(int now, int l, int r){
		if(!lazy[now]){
			return ;
		}
		tree[now] = (c[r + 1] - c[l]) - tree[now];
		if(l < r){
			lazy[now * 2] ^= 1;
			lazy[now * 2 + 1] ^= 1;
		}
		lazy[now] = false;
	}
	void update(int l, int r, int wl, int wr, int now){
		push(now, l, r);
		if(l > r || l > wr || r < wl){
			return ;
		}
		if(wl <= l && r <= wr){
			lazy[now] = true;
			push(now, l, r);
			return ;
		}
		int mid = (l + r) >> 1;
		update(l, mid, wl, wr, now * 2);
		update(mid + 1, r, wl, wr, now * 2 + 1);
		tree[now] = tree[now * 2] + tree[now * 2 + 1];
	}
} seg;

void solve(){
	int l, n;
	cin >> l >> n;
	vector<int> query;
	c.push_back(0);
	c.push_back(l);
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		c.push_back(x);
		query.push_back(x);
	}
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	for(auto x: query){
		int idx = lower_bound(c.begin(), c.end(), x) - c.begin();
		seg.update(1, c.size() - 2, idx, c.size() - 1, 2);
		cout << n - seg.tree[1] << "\n";
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
