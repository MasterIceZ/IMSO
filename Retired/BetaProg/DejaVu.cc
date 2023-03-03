/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Deja Vu
 * ALGO		: Dynamic Programming
 * DATE		: 27 Feb 2023
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
ll a[MxN], dp[MxN];
vector<ll> pos[MxN];

inline void solution(){
	int n, sz = 0;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		int idx = upper_bound(dp, dp + sz, a[i]) - (dp);
		if(idx == sz){
			sz++;
		}
		dp[idx] = a[i];
		pos[idx].emplace_back(a[i]);
	}
	ll answer = 0ll, last_max = 1e18 + 100;
	for(int i=sz-1; i>=0; --i){
		ll current_max = 0ll;
		dbg(pos[i]);
		for(auto x: pos[i]){
			if(x > last_max){
				continue;
			}
			current_max = max(current_max, x);
		}
		last_max = current_max;
		answer = answer + current_max;
	}
	cout << sz << " " << answer ;
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
