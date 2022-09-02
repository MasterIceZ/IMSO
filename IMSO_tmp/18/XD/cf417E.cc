/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Sagheer and Apple Tree
 * ALGO		: Dynamic Programming
 * DATE		: 29 Aug 2022
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

const int MxN = ;
int a[MxN];
vector<int> adj[MxN];

void dfs(int u, int p){
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
	}
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=2; i<=n; ++i){
		cin >> x;
		adj[x].emplace_back(i);
	}
	dfs(x, 0);
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
