/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Blind Ballot
 * ALGO		: Kosaraju's Algorirthm, Strongly Connected Components
 * DATE		: 12 Aug 2022
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

const int MxN = 20020;
int a[4];
vector<int> adj[MxN], rev[MxN], comp[MxN];
stack<int> st;
bitset<MxN> visited;

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

void dfs2(int u, int p, int id){
	visited[u] = true;
	comp[id].emplace_back(u);
	for(auto x: rev[u]){
		if(x == p || visited[x]){
			continue;
		}
		dfs2(x, u, id);
	}
}

inline void solution(){
	int n, w;
	cin >> n >> w;
	for(int i=1, t; i<=w; ++i){
		cin >> t >> a[1] >> a[2] >> a[3];
		if(t == 1){
			adj[a[2]].emplace_back(a[1]); adj[a[3]].emplace_back(a[1]);
			rev[a[1]].emplace_back(a[2]); rev[a[1]].emplace_back(a[3]);
		}
		else if(t == 2){
			adj[a[1]].emplace_back(a[2]); adj[a[1]].emplace_back(a[3]);
			rev[a[2]].emplace_back(a[1]); rev[a[3]].emplace_back(a[1]);
		}
		else{
			adj[a[1]].emplace_back(a[2]); adj[a[2]].emplace_back(a[3]); adj[a[3]].emplace_back(a[1]);
			rev[a[2]].emplace_back(a[1]); rev[a[3]].emplace_back(a[2]); rev[a[1]].emplace_back(a[3]);
		}
	}
	for(int i=1; i<=n; ++i){
		if(visited[i]){
			continue;
		}
		dfs(i, 0);
	}
	visited = 0;
	int it = 0;
	while(!st.empty()){
		int now = st.top(); st.pop();
		if(visited[now]){
			continue;
		}
		dfs2(now, 0, ++it);
	}
	cout << it << "\n";
	for(int i=1; i<=it; ++i){
		cout << comp[i].size() << " " ;
		sort(comp[i].begin(), comp[i].end());
		for(auto x: comp[i]){
			cout << x << " ";
		}
		cout << "\n";
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
