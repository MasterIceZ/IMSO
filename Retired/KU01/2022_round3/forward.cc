/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Forward
 * ALGO		: Depth First Search
 * DATE		: 26 Nov 2022
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
bitset<MxN> visited;

void dfs(int u){
	visited[u] = true;
	for(auto x: adj[u]){
		if(!visited[x]){
			dfs(x);
		}
	}
}

inline void solution(){
	int n, s;
	cin >> n >> s;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		if(x != 0){
			adj[i].emplace_back(x);
		}
	}
	dfs(s);
	cout << visited.count();
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
