/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Finding a Centroid
 * ALGO		: Centroid Decomposition
 * DATE		: 8 Jan 2023
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
int n, subtree_size[MxN];
vector<int> adj[MxN];

int build_size(int u, int p){
	subtree_size[u] = 1;
	for(auto v: adj[u]){
		if(v == p || subtree_size[v] != 0){
			continue;
		}
		subtree_size[u] = subtree_size[u] + build_size(v, u);
	}
	return subtree_size[u];
}

int get_centroid(int u, int p){
	for(auto v: adj[u]){
		if(v == p){
			continue;
		}
		if(subtree_size[v] * 2 > n){
			return get_centroid(v, u);
		}
	}
	return u;
}

inline void solution(){
	cin >> n;
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	build_size(1, 0);
	cout << get_centroid(1, 0);
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
