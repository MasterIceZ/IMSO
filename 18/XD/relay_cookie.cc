/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: relay cookie
 * ALGO		: Dynamic Programming on Tree, Dynamic Programming
 * DATE		: 12 Sep 2022
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

int dp[MxN], mx_hei;
ll c[MxN], qs[MxN], x;

void dfs(int u, int p, int hei){
	dp[u] = hei;
	mx_hei = max(dp[u], mx_hei);
	for(auto x: adj[u]){
		if(x == p || hei[x]){
			continue;
		}
		dfs(x, u, hei + 1);
	}
}

inline void solution(){
	int n, k;
	cin >> n >> k;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1, 0, 1);
	for(int i=1; i<=n; ++i){
		cin >> x;
		qs[dp[i]] = qs[dp[i]] + x;
	}
	for(int i=1; i<=mx_hei; ++i){
		qs[i] = qs[i - 1] + qs[i];
	}
	for(int i=1; i<=n; ++i){
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
