/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Ultimate Werewolf
 * ALGO		: Dynamic Programming on Tree
 * DATE		: 26 Feb 2023
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
vector<int> adj[MxN];
int stp, root, a[MxN];
pair<int, int> dp[MxN];
bitset<MxN> visited;

void getCycle(int u){
	visited[u] = true;
	if(visited[a[u]]){
		stp = u;
		root = a[u];
		return ;
	}
	getCycle(a[u]);
}

void clear(int u){
	visited[u] = false;
	for(auto x: adj[u]){
		if(!visited[x]){
			continue;
		}
		clear(x);
	}
}

void dfs(int u, bool flag){
	dp[u] = make_pair(1, 0);
	for(auto x: adj[u]){
		if(visited[x]){
			continue;
		}
		visited[x] = true;
		dfs(x, flag);
		dp[u] = make_pair(dp[u].first + min(dp[x].first, dp[x].second), dp[u].second + dp[x].first);
	}
	if(flag && root == u){
		dp[u].second = 1e9 + 100;
	}
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		adj[a[i]].emplace_back(i);
	}
	int answer = 0;
	for(int i=1; i<=n; ++i){
		if(visited[i]){
			continue;
		}
		getCycle(i);
		dbg(stp, root);
		clear(stp);
		visited[stp] = true;
		dfs(stp, false);
		int cur_1 = dp[stp].first;
		clear(stp);
		visited[stp] = true;
		dfs(stp, true);
		int cur_2 = dp[stp].second;
		answer += min(cur_1, cur_2);
	}
	cout << answer;
	visited = 0;
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
