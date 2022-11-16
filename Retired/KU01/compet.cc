/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Compet
 * ALGO		: Segment Tree
 * DATE		: 16 Nov 2022
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

const int MxN = 35;
int n, c, t[MxN << 2], v[MxN][MxN];

void build(int l, int r, int idx){
	if(l > r){
		return ;
	}
	if(l == r){
		t[idx] = l;
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, idx << 1);
	build(mid + 1, r, idx << 1 | 1);
	int winner = v[t[idx << 1]][t[idx << 1 | 1]];
	if((t[idx << 1] == c || t[idx << 1 | 1] == c) && winner != c){
		t[idx] = c;
		c = 0;
	}
	else{
		t[idx] = winner;
	}
}

inline void solution(){
	cin >> n >> c;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cin >> v[i][j];
		}
	}
	build(1, n, 1);
	cout << t[1];
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
