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

multiset<ll> dp;

inline void solution(){
	int n, cur;
	cin >> n >> cur;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		dp.emplace(x);
	}
	for(int i=1; i<=n; ++i){
		auto it = dp.lower_bound(cur);
		int more_val;
		if(it == dp.end()){
			more_val = 1e9 + 100;
		}
		else{
			more_val = *it;
		}
		--it;
		int min_val = *it;
		if(more_val < min_val){
			
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
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
