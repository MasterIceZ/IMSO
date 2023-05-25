/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Icy Land
 * ALGO		: 
 * DATE		: 6 May 2023
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

const int MxN = 200020;
vector<pair<int, ll>> adj[MxN];
ll w, t[MxN], dp[2][MxN], dp_2[MxN], mem[MxN];

// dp[0][u] = maximum dist from leaf to u
// dp[1][u] = 2nd maximum dist from leaf to u

// dp_2[u] = maximum dist from 1 to u

// mem[u] = real cost

void dfs(int u, int p){
	for(auto x: adj[u]){
		if(x.first == p){
			continue;
		}
		dfs(x.first, u);
		ll nxt = dp[0][x.first] + x.second;
		// sliding max
		if(dp[0][u] < nxt){
			dp[1][u] = dp[0][u];
			dp[0][u] = nxt;
		}
		else if(dp[1][u] < nxt){
			dp[1][u] = nxt;
		}
	}
}

void dfs_2(int u, int p){
	for(auto x: adj[u]){
		if(x.first == p){
			continue;
		}
		ll use_max = dp[1][u], nxt = dp[0][x.first] + x.second;
		if(dp[0][u] != nxt){
			use_max = dp[0][u];
		}
		dp_2[x.first] = max(dp_2[u], use_max) + x.second;
		dfs_2(x.first, u);
	}
	mem[u] = max(dp[0][u], dp_2[u]);
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i=1; i<=m; ++i){
		cin >> t[i];
	}
	dfs(1, 0);
	dbg(to_string(dp[0], 1, n));
	dbg(to_string(dp[1], 1, n));
	dfs_2(1, 0);
	dbg(to_string(dp_2, 1, n));
	sort(t + 1, t + m + 1, greater<ll> ());
	sort(mem + 1, mem + n + 1);
	ll res = 0ll;
	for(int i=1; i<=m; ++i){
		res += t[i] * mem[i];
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
