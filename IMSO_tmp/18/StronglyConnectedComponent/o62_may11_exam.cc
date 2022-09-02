/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o62_may11_exam
 * ALGO		: Strongly Connected Component, Kosaraju's Algorithm
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

const int MxN = 100100;
string s;
int comp[MxN], deg[MxN];
vector<int> adj[MxN], rev[MxN], adj2[MxN];
bitset<MxN> visited, nec;
stack<int> st;

void dfs(int u, int p){
	visited[u] = true;
	for(auto x: adj[u]){
		if(visited[x] || x == p){
			continue;
		}
		dfs(x, u);
	}
	st.emplace(u);
}

void dfs2(int u, int p, int c){
	visited[u] = true;
	comp[u] = c;
	for(auto x: rev[u]){
		if(visited[x] || x == p){
			continue;
		}
		dfs2(x, u, c);
	}
}

inline void solution(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> s;
		s = " " + s;
		for(int j=1; j<=k; ++j){
			if(s[i] == '1'){
				adj[i].emplace_back(j + n);
				rev[j + 1].emplace_back(i);
			}
			else{
				adj[j + 1].emplace_back(i);
				rev[i].emplace_back(j + n);
			}
		}
	}
	for(int i=1; i<=n+k; ++i){
		if(!visited[i]){
			dfs(i, 0);
		}
	}
	visited = 0;
	int it = 0;
	while(!st.empty()){
		int now = st.top();
		st.pop();
		if(visited[now]){
			continue;
		}
		dfs2(now, 0, ++it);
	}
	for(int i=1; i<=n+k; ++i){
		for(auto x: adj[i]){
			if(comp[i] != comp[x]){
				adj2[comp[i]].emplace_back(comp[x]);
			}
		}
	}
	for(int i=1; i<=n; ++i){
		nec[comp[i]] = true;
	}
	for(int i=1; i<=it; ++i){
		if(nec[i]){
			for(auto x: adj2[i]){
				deg[x]++;
			}
		}
	}
	set<int> st; // find out 1st
	int cc = -1;
	for(int i=1; i<=n; ++i){
		if(!deg[comp[i]]){
			st.emplace(comp[i]);
			cc = comp[i];
		}
	}
	if((int) st.size() != 1){
		cout << -1;
		return ;
	}
	for(int i=1; i<=n; ++i){
		if(comp[i] == cc){
			cout << i << " ";
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
