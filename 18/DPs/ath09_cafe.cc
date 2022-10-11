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

const int MxN = 1010;
vector<int> adj[MxN];
int dp[MxN][4];

void dfs(int u, int p){
	int all_cafe = 0;
	bool gone = false;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		gone = true;
		dfs(x, u);
		all_cafe = all_cafe + max({dp[x][0], dp[x][1], dp[x][2]});
		dp[u][1] = max({dp[u][1], 1 + dp[x][0]});
		dp[u][2] = max({dp[u][2], 1 + dp[x][1]});
	}
	if(!gone){
		dp[u][1] = 1;
	}
	dp[u][0] = all_cafe;
}

inline void solution(){
	int n, u, v;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	memset(dp, 0, sizeof dp);
	dfs(1, 0);
	cout << max({dp[1][0], dp[1][1], dp[1][2]});
	for(int i=1; i<=n; ++i){
		adj[i].clear();
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
