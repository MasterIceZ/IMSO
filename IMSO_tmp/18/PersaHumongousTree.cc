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

const int MxN = 1e5 + 10;
pair<int, int > a[MxN];
bitset<MxN> visited;

pair<int, int> dfs(int u, int p){
	if(visited[u]){
		return dp[u];
	}
	pair<int, int> sum = make_pair(0, 0);
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
	}
	visited[u] = true;
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	visited = 0;
	dfs(1, 0);
	cout << max(dp[1].first, dp[1].second);
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
