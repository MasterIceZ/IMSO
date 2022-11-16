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
int n, c, t[1 << 17], v[MxN][MxN], cnt[MxN];

inline void solution(){
	cin >> n >> c;
	c--;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> v[i][j];
			v[i][j]--;
		}
	}
	for(int i=0; i<n; ++i){
		t[i + n] = i;
	}
	for(int i=n-1; i>0; --i){
		int winner = v[t[i << 1]][t[i << 1 | 1]];
		if((t[i << 1] == c || t[i << 1 | 1] == c) && winner != c){
			t[i] = c;
			c = -1;
		}
		else{
			t[i] = winner;
		}
	}
	cout << t[1] + 1;
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
