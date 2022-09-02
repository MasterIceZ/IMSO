/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Welcome to 2017 (Large)
 * ALGO		: Brute Force 
 * DATE		: 6 Jul 2022
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

int used[4444];

inline void solution(){
	int n;
	cin >> n;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		used[x]++;
	}
	int now = 1e9 + 100, res = -1;
	for(int i=1; i<=4000; ++i){
		if(abs(2017 - i) >= now || used[i] != 1){
			continue;
		}
		res = i;
		now = abs(2017 - i);
	}	
	cout << res;
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
