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

const int MxN = 50050;

int a[MxN];

struct Tree{
	vector<int> tree[4 * MxN];
	void build(int l, int r, int now){
		if(l > r){
			return ;
		}	
		if(l == r){
			tree[now].push_back(a[l]);
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, now * 2);
		build(mid + 1, r, now * 2 + 1);
		int i = 0, j = 0;
		vector<int> L = tree[now * 2];
		vector<int> R = tree[now * 2 + 1];
		vector<int> res;
		while(i < L.size() && j < R.size() && res.size() < 10){
			if(L[i] < R[j]){
				res.push_back(L[i++]);
			}
			else{
				res.push_back(R[j++]);
			}
		}
		while(i < L.size() && res.size() < 10){
			res.push_back(L[i++]);
		}
		while(j < R.size() && res.size() < 10){
			res.push_back(R[j++]);
		}
		tree[now] = res;
	}
	vector<int> read(int l, int r, int wl, int wr, int now){
		if(l > r || r < wl || l > wr){
			return {};
		}
		if(wl <= l && r <= wr){
			return tree[now];
		}
		int mid = (l + r) >> 1;
		vector<int> L = read(l, mid, wl, wr, now * 2);
		vector<int> R = read(mid + 1, r, wl, wr, now * 2 + 1);
		int i = 0, j = 0;
		vector<int> res;
		while(i < L.size() && j < R.size() && res.size() < 10){
			if(L[i] < R[j]){
				res.push_back(L[i++]);
			}
			else{
				res.push_back(R[j++]);
			}
		}
		while(i < L.size() && res.size() < 10){
			res.push_back(L[i++]);
		}
		while(j < R.size() && res.size() < 10){
			res.push_back(R[j++]);
		}
		return res;
	}
} seg;

void solve(){
	int n, q, l, r;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	seg.build(1, n, 1);
	while(q--){
		cin >> l >> r;
		l++, r++;
		vector<int> now = seg.read(1, n, l, r, 1);
		for(auto x: now){
			cout << x << " ";
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
