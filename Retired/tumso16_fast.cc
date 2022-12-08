/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Fast Aid
 * ALGO		: ?
 * DATE		: 6 Dec 2022
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

const int MxN = 10010;
using pii = pair<int, int>;

vector<int> adj[MxN];
vector<pair<pii, pii>> edges; // (sorted, real)
bitset<MxN> visited;
stack<int> st;
int comp[MxN], sz[MxN];

void dfs(int u, int p){
	visited[u] = true;
	for(auto x: adj[u]){
		if(x == p || visited[x]){
			continue;
		}
		dfs(x, u);
	}
	st.emplace(u);
}

void dfs_2(int u, int p, int c){
	comp[u] = c;
	sz[c] = sz[c] + 1;
	for(auto x: adj[u]){
		if(x == p || comp[c]){
			continue;
		}
		dfs_2(x, u, c);
	}
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(w);
		edges.emplace_back(make_pair(min(u, v), max(u, v)), make_pair(u, v));
	}
	for(int i=1; i<=n; ++i){
		if(visited[i]){
			continue;
		}
		dfs(i, 0);
	}
	int it = 0;
	while(!st.empty()){
		int now = st.top(); st.pop();
		if(comp[now]){
			continue;
		}
		dfs_2(now, 0, ++it);
	}
	if(it == 1){
		cout << "OK!";
		return ;
	}
	for(int i=1; i<=n; ++i){
		
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
