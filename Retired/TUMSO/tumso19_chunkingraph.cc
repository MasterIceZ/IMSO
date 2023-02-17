/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Chunk in Graph
 * ALGO		: Kahn's Algorithm
 * DATE		: 4 Feb 2023
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
vector<int> adj[MxN];
int in[MxN];
bitset<MxN> visited;
queue<int> q;
stack<int> st;

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
		in[u]++, in[v]++;
	}
	for(int i=1; i<=n; ++i){
		if(in[i] == 1){
			q.emplace(i);
			visited[i] = true;
		}
	}
	int cnt = 0;
	while(!q.empty()){
		int now = q.front(); q.pop();
		cnt++;
		for(auto x: adj[now]){
			if(!visited[x] && --in[x] == 1){
				visited[x] = true;
				q.emplace(x);
			}
		}
	}
	for(int i=1; i<=n; ++i){
		if(visited[i]){
			continue;
		}
		st.emplace(i);
		while(!st.empty()){
			int now = st.top(); st.pop();
			visited[now] = true;
			for(auto x: adj[now]){
				if(visited[x]){
					continue;
				}
				st.emplace(x);
			}
		}
		cnt++;
	}
	cout << cnt;
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
