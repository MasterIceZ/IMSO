/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Fast Aid
 * ALGO		: 
 * DATE		: 14 Jan 2023
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

struct special_edge{
	int v;
	pair<int, int> real;
	special_edge(int _v, int _a, int _b): v(_v), real({_a, _b}) {}
};

struct PQ{
	int val, u, v;
	bool operator < (const PQ& o) const {
		if(val != o.val){
			return val < o.val;
		}
		if(u != o.u){
			return u > o.u;
		}
		return v > o.v;
	}
	PQ(int _val, int _u, int _v):
		val(_val), u(_u), v(_v) {}
};

const int MxN = 10010;
vector<int> adj[MxN];
vector<special_edge> adj2[MxN];
int n, m, it, component[MxN], subtree_size[MxN];
bitset<MxN> visited;
stack<int> st;

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

void dfs_2(int u, int p){
	component[u] = it;
	for(auto x: adj[u]){
		if(x == p || component[x]){
			continue;
		}
		dfs_2(x, u);
	}
}

int gen_subtree(int u, int p){
	subtree_size[u] = 1;
	for(auto x: adj2[u]){
		if(x.v == p || subtree_size[x.v]){
			continue;
		}
		subtree_size[x.v] += gen_subtree(x.v, u);
	}
	return subtree_size[u];
}

int get_centroid(int u, int p){
	for(auto x: adj2[u]){
		if(x.v == p){
			continue;
		}
		if(subtree_size[x.v] * 2 > n){
			return get_centroid(x.v, u);
		}
	}
	return u;
}

inline void solution(){
	cin >> n >> m;
	vector<pair<int, int>> edges;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
		edges.emplace_back(u, v);
	}
	dfs(1, 0);
	visited = 0;
	while(!st.empty()){
		int now = st.top(); st.pop();
		if(visited[now]){
			continue;
		}
		++it;
		dfs_2(now, 0);
	}
	if(it == 1){
		cout << "OK!";
		return ;
	}
	for(auto x: edges){
		int cu = component[x.first];
		int cv = component[x.second];
		adj2[cu].emplace_back(cv, x.first, x.second);
		adj2[cv].emplace_back(cu, x.first, x.second);
	}
	gen_subtree(1, 0);
	int centroid = get_centroid(1, 0);
	priority_queue<PQ> pq;
	for(int i=1; i<=n; ++i){
		if(component[i] != centroid){
			continue;
		}
		for(auto x: adj[i]){
			pq.emplace(adj[x].size(), min(i, x), max(i, x));
		}
	}
	cout << pq.top().u << " " << pq.top().v;
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
