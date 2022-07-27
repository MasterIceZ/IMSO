/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o62_may09_parent
 * ALGO		: Disjoint Set Union, Lowest Common Ancestor, Binary Lifting
 * DATE		: 12 Jul 2022
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

struct Query{
	int t, x, y;
	Query(int a, int b, int c): t(a), x(b), y(c) {}
	Query(int a, int b): t(a), x(b), y(-1) {}
};

const int MxN = 100010;
vector<int> adj[MxN];
int parent[MxN], level[MxN], dp[22][MxN];

int find_root(int u){
	return u == parent[u]? u: parent[u] = find_root(parent[u]);
}

void dfs(int u, int p){
	level[u] = level[p] + 1;
	dp[0][u] = p;
	for(auto x: adj[u]){
		if(x == p || level[x]){
			continue;
		}
		dfs(x, u);
	}
}

inline int get_lca(int u, int v){
	if(level[u] < level[v]){
		swap(u, v);
	}
	for(int state=17; state>=0; --state){
		if(level[dp[state][u]] >= level[v]){
			u = dp[state][u];
		}
	}
	if(u == v){
		return u;	
	}
	for(int state=17; state>=0; --state){
		if(dp[state][u] != dp[state][v]){
			u = dp[state][u];
			v = dp[state][v];
		}
	}
	return dp[0][u];
}

inline int get_dist(int u, int v){
	int lca = get_lca(u, v);
	return level[u] + level[v] - 2 * level[lca];
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	vector<Query> offline;
	for(int i=1, t, x, y; i<=m; ++i){
		cin >> t;
		if(t == 1){
			cin >> x >> y;
			adj[x].emplace_back(y);
			adj[y].emplace_back(x);
			offline.emplace_back(t, x, y);
		}
		else if(t == 2){
			cin >> x;
			offline.emplace_back(t, x);
		}
		else{
			cin >> x >> y;
			offline.emplace_back(t, x, y);
		}
	}
	iota(parent + 1, parent + n + 1, 1);
	for(int i=1; i<=n; ++i){
		if(level[i]){
			continue;
		}
		dfs(i, 0);
	}
	for(int state=1; state<=17; ++state){
		for(int i=1; i<=n; ++i){
			dp[state][i] = dp[state - 1][dp[state - 1][i]];
		}
	}
	for(auto x: offline){
		if(x.t == 1){
			parent[find_root(x.x)] = find_root(x.y);
		}
		else if(x.t == 2){
			parent[find_root(x.x)] = x.x;
			parent[x.x] = x.x;
		}
		else{
			int rx = find_root(x.x);
			if(get_dist(x.x, rx) < get_dist(x.y, rx)){
				cout << x.x << "\n";
			}
			else{
				cout << x.y << "\n";
			}
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
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
