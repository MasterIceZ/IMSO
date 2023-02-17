/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Tetris Battle
 * ALGO		: Segment Tree
 * DATE		: 16 Jan 2023
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

const int MxN = 100010;
int n, q, a[MxN], t[MxN * 4], x;
string s;

void build(int l, int r, int idx){
	if(l > r){
		return ;
	}
	if(l == r){
		t[idx] = a[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, idx << 1);
	build(mid + 1, r, idx << 1 | 1);
	t[idx] = t[idx << 1] + t[idx << 1 | 1];
}

void update(int l, int r, int id, int v, int idx){
	if(l > r || l > id || r < id){
		return ;
	}
	if(l == r){
		t[idx] = v;
		return ;
	}
	int mid = (l + r) >> 1;
	update(l, mid, id, v, idx << 1);
	update(mid + 1, r, id, v, idx << 1 | 1);
	t[idx] = t[idx << 1] + t[idx << 1 | 1];
}

int query(int l, int r, int wl, int wr, int idx){
	if(l > r || l > wr || r < wl){
		return 0;
	}
	if(wl <= l && r <= wr){
		return t[idx];
	}
	int mid = (l + r) >> 1;
	return query(l, mid, wl, wr, idx << 1) + query(mid + 1, r, wl, wr, idx << 1 | 1);
}

inline void solution(){
	cin >> n >> q >> s;
	for(int i=1; i<=n; ++i){
		a[i] = s[i - 1] - '0';
	}
	build(1, n, 1);
	while(q--){
		cin >> x;
		if(x == 1){
			int u, v;
			cin >> u >> v;
		}
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
