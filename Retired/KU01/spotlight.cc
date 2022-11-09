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

int a[444], l, r;

inline void solution(){
	cin >> l >> r;
	l++;
	if(l < r){
		for(; l<=r; ++l){
			a[l]++;
		}
	}
	else{
		for(int i=1; i<=360; ++i){
			a[i]++;
		}
		for(; l<=r; ++l){
			a[l]--;
		}
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
	}
	int maxx = 0;
	for(int i=1, cnt = 0; i<=360; ++i){
		if(a[i] == 0){
			cnt = 0;
		}
		else{
			maxx = max(maxx, ++cnt);
		}
	}
	cout << maxx << "\n";
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
