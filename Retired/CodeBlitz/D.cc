/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

struct Node{
	int v1, v2, l, r;
};

const int MxN = 100010;
int n, q, a, b;
Node t[MxN << 2];

Node merge_node(Node a, Node b){
	Node res;
	res.l = a.l;
	res.r = b.r;
	res.v1 = min({a.v1, a.v2, b.v1, b.v2});
	res.v2 = max({a.v1, a.v2, b.v1, b.v2});
	return res;
}

void build(int l, int r, int idx){
	if(l > r){
		return ;
	}
	if(l == r){
		t[idx].l = l;
		t[idx].r = r;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, idx << 1);
	build(mid + 1, r, idx << 1 | 1);
	t[idx] = merge_node(t[idx << 1], t[idx << | 1]);
}

void push_lazy(int l, int r, int idx){
	t[idx].v = 
	if(l == r){
		return ;
	}
	lazy[idx << 1] = ;
	lazy[idx << 1 | 1] = ;
}

void update(int l, int r, int wl, int wr, int v, int idx){
	push_lazy(l, r, idx);
	if(l > r || r < wl || l > wr){
		return ;
	}
	if(wl <= l && r <= wr){
		t[idx].l ;
		lazy[idx] = ;
	}
}

inline void solution(){
	cin >> n >> q >> a >> b;
	while(l
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
