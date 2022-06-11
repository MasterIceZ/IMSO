/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Xenia and Bit Operations
 * ALGO		: Segment Tree
 * DATE		: 19 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int tree[(1 << 18) * 4];

int compute(int a, int b, bool ok){
	if(ok){
		return a | b;
	}
	return a ^ b;
}

bool build(int l, int r, int idx){
	if(l > r){
		return ;
	}
	if(l == r){
		cin >> tree[idx];
		return true;
	}
	int mid = (l + r) >> 1;
	bool ok = build(l, mid, idx * 2);
	ok |= build(mid + 1, r, idx * 2 + 1);
	tree[idx] = compute(idx + 1, idx * 2 + 1, ok);
	return !ok;
}

int read(int l, int r, int wl, int wr, int idx){
	if(l > r || l > wr || r < wl){
		return ;
	}
	if(l == r){
		return tree[idx];
	}
	int mid = (l + r) >> 1;
	return read(l, mid, wl, wr, idx * 2) ^ read(mid + 1, r, wl, wr, idx * 2 + 1);
}

void solve(){
	int n, m;
	cin >> n >> m;
	build(1, 1 << n);
	while(m--){
		cin >> l >> r;
		cout << 
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
