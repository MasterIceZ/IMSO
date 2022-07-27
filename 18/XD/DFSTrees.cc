/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: DFS Trees
 * ALGO		: Lowest Common Anecestor, Binary Lifting
 * DATE		: 22 Jul 2022
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

const int MxN = 1e5 + 20;
vector<int> adj[MxN];
int parent[MxN], dp[MxN][20];

int find_root(int u){
	if(parent[u] == u){
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

void dfs(int u, int p){
	level[u] = level[p] + 1;
	dp[u][0] = p;
	for(auto x: adj[u]){
		if(x == p){
			continue ;
		}
		dfsd(x, u);
	}
}

inline int get_lca(int u, int v){
	if(level[u] > level[v]){
		swap(u, v);
	}
	for(int state=17; state>=0; --state){
		if(level[u] <= level[dp[v][state]]){
			v = dp[state][v];
		}
	}
	if(u == v){
		return u;
	}
	for(int state=17; state>=0; --state){
		if(dp[u][state] != dp[v][state]){
			u = dp[u][state];
			v = dp[v][state];
		}
	}
	return dp[u][0];
}

inline void solution(){
	int n, m, u, v;
	cin >> n >> m;
	iota(parent + 1, parent + n + 1, 1);
	vector<pair<int, int>> oth;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		int ru = find_root(u), rv = find_root(rv);
		if(ru == rv){
			oth.emplace_back(u, v);
		}
		else{
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
			p[ru] = rv;
		}
	}
	dfs(1, 0);
	// Binary Lifting
	for(int state=1; state<=17; ++state){
		for(int i=1; i<=n; ++i){
			dp[i][state] = dp[dp[i][state - 1]][state - 1];
		}
	}
	for(auto x: oth){
		int ancestor = get_lca(x.first, x.second);
		if(level[x.first] > level[x.second]){
			u[
		}
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
