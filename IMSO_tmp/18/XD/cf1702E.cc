/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Split Into Two Sets
 * ALGO		: Bipartite Matching
 * DATE		: 11 Jul 2022
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

const int MxN = 2e5 + 20;
int a[MxN], b[MxN], deg[MxN], color[MxN];
vector<int> p[MxN], adj[MxN];

bool dfs(int u, int p, int c){
	if(color[u]){
		return color[u] == c;
	}
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		if(!dfs(x, u, 3 - c)){
			return false;
		}
	}
	return true;
}

inline void solution(){
	memset(deg, 0, sizeof deg);
	memset(color, 0, sizeof color);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i] >> b[i];
		deg[a[i]]++, deg[b[i]]++;
	}
	bool ok = true;
	for(int i=1; i<=n; ++i){
		if(a[i] == b[i] || deg[a[i]] > 1 || deg[b[i]] > 1){
			ok = false;
		}
	}
	if(!ok){
		cout << "NO";
		return ;
	}
	for(int i=1; i<=n; ++i){
		p[a[i]].emplace_back(i); p[b[i]].emplace_back(i);
	}
	for(int i=1; i<=n; ++i){
		if(p[i].size() == 2){
			adj[p[i][0]].emplace_back(p[i][1]);
			adj[p[i][1]].emplace_back(p[i][0]);
		}
	}
	ok = true;
	for(int i=1; i<=n; ++i){
		if(!color[i]){
			ok &= dfs(i, 0, 1);
		}
	}
	cout << (ok ? "YES": "NO");
	for(int i=1; i<=n; ++i){
		adj[i].clear(); p[i].clear();
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
