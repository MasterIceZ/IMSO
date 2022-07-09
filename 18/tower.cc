/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Tower
 * ALGO		: Dynamic Programming
 * DATE		: 5 Jul 2022
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

const int MxN = 10010;

int dp[MxN];
vector<int> adj[MxN];

inline void solution(){
	int k, n, m;
	cin >> k >> n >> m;
	for(int i=1, l, h; i<=m; ++i){
		cin >> l >> h;
		adj[l].emplace_back(h);
	}
	memset(dp, 0x3f, sizeof dp);
	dp[1] = 0;
	for(int i=1; i<=n; ++i){
		for(auto x: adj[i]){
			dp[x] = min(dp[x], dp[i] + 1);
		}
	}
	for(int i=n; i>=1; --i){
		if(dp[i] > k){
			continue;
		}
		cout << i;
		return ;
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
