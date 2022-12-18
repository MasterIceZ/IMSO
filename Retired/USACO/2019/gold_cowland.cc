/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Cow Land
 * ALGO		: Heavy Light Decomposition, Lowest Common Ancestor, Segment Tree
 * DATE		: 11 Dec 2022
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
const int LG = 22;
int e[MxN], lift[LG][MxN], sz[MxN], level[MxN];
vector<int> adj[MxN];

void dfs(int u, int p){
	lift[0][u] = p;
	level[u] = level[p] + 1;
	for(auto x: adj[u]){
		if(x == p || level[x]){
			continue;
		}
		dfs(x, u);
		sz[u] += sz[x];
	}
}

void buildHLD(int u, int t, int p){
	seg[u] = 
}

inline void solution(){
	int n, q;
	cin >> n >> q;
	for(int i=1, x; i<=n; ++i){
		cin >> e[i];
		sz[i] = 1;
	}
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1, 0);
	for(int state=1; state<LG; ++state){
		for(int i=1; i<=n; ++i){
			lift[state][i] = lift[state - 1][lift[state - 1][i]];
		}
	}
	buildHLD(1, 1, 0);
	return ;
}

signed main(){
	
#ifndef _DEBUG
	freopen("cowland.in", "r", stdin);
	freopen("cowland.out", "w", stdout);
#endif

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
