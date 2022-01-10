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
	pair<int, int> operator + (const pair<int, int> a, const pair<int, int> b){
		return pair<int, int>(a.first + b.first, a.second + b.second);
	}
	pair<int, int> tree[4 * MxN];
	bool lazy[4 * MxN];
	void build(int l, int r, int now){
		if(l == r){
			tree[now] = pair<int, int>(v[l - 1] - v[l], 0);
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, now * 2);
		build(mid + 1, r, now * 2 + 1);
		tree[now] = tree[now * 2] + tree[now];
	}
	void lzy(int now){
		if(lazy[now]){
			lazy[now * 2] ^= true;
			lazy[now * 2 + 1] ^= true;
			swap(tree[now].first, tree[now].second);
			lazy[now] = false;
		}
	}
	void update(int l, int r, int wl, int wr, int v, int now){
		if(l > r || wl > r || wr < l){
			return ;
		}
		if(wl <= l && r <= wr){
			tree[now] = ;
			return ;
		}
		lzy(now);
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
	for(int i=1; i<=n; ++i){}
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
