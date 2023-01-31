/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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

struct Edge{
	int u, v, w;
	Edge(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
};

struct State{
	int v, w;
	State(int _v, int _w):
		v(_v), w(_w) {}
	bool operator < (const State& o) const {
		return w > o.w;
	}
};

const int MxN = 100010;
vector<pair<int, int>> adj[MxN], adj_2[MxN];
priority_queue<State> pq;
bitset<MxN> visited;
stack<int> st;
vector<Edge> edges;
int comp[MxN];

void dfs(int u, int p){
	visited[u] = true;
	for(auto x: adj[u]){
		if(x.first == p){
			continue;
		}
		dfs(x.first, u);
	}
	st.emplace(u);
}

void dfs2(int u, int p, int it){
	visited[u] = true;
	comp[u] = it;
	for(auto x: adj[u]){
		if(x.first == p){
			continue;
		}
		dfs2(x.first, u, it);
	}
}

inline void solution(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		edges.emplace_back(u, v, w);
	}
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			dfs(i, 0);
		}
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
	int answer_1 = 0;
	for(auto edge: edges){
		if(comp[edge.u] != comp[edge.v]){
			answer_1 += edge.w * 2;
			continue;
		}
		answer_1 += edge.w;
		adj_2[edge.u].emplace_back(edge.v, edge.w);
		adj_2[edge.v].emplace_back(edge.u, edge.w);
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
