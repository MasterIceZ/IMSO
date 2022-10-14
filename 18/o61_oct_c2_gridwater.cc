/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o61_oct_c2_gridwater
 * ALGO		: 
 * DATE		: 14 Oct 2022
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
	bool operator < (const Edge& o) const {
		return w < o.w;
	}	
	Edge(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
};

const int MxN = 550 * 550;

vector<Edge> edges, unused;
vector<pair<int, int>> adj[MxN], adj2[MxN];
set<int> vertex;
int max_vertex, parent[MxN], sz[MxN], level[MxN];
pair<int, int> lift[MxN][22];

inline int get_id(int i, int j){
	return i * 419 + j;
}

inline void add_edge(int a_i, int a_j, int b_i, int b_j, int w){
	int u = get_id(a_i, a_j), v = get_id(b_i, b_j);
	edges.emplace_back(u, v, w);
	adj[u].emplace_back(v, w);
	adj[v].emplace_back(u, w);
	vertex.emplace(u);
	vertex.emplace(v);
	max_vertex = max({max_vertex, u, v});
	return ;
}

int find_root(int u){
	while(u != parent[u]){
		u = parent[u];
	}
	return u;
}

void unite(int u, int v){
	int ru = find_root(u);
	int rv = find_root(v);
	if(ru == rv){
		return ;
	}
	if(sz[ru] > sz[rv]){
		parent[rv] = ru;
		sz[ru] = max(sz[ru], sz[rv] + 1);
	}
	else{
		parent[ru] = rv;
		sz[rv] = max(sz[rv], sz[ru] + 1);
	}
}

void dfs(int u, int p){
	level[u] = level[p] + 1;
	lift[u][0].first = p;
	for(auto x: adj2[u]){
		if(x.first == p){
			continue;
		}
		lift[x.first][0].second = x.second;
		dfs(x.first, u);
	}
}

inline void solution(){
	int n, m, w;
	cin >> n >> m;
	for(int i=2; i<=m; ++i){
		cin >> w;
		add_edge(1, i - 1, 1, i, w);
	}
	for(int i=2; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> w;
			add_edge(i - 1, j, i, j, w);
		}
		for(int j=2; j<=m; ++j){
			cin >> w;
			add_edge(i, j - 1, i, j, w);
		}
	}
	assert(max_vertex < MxN);	
	for(auto x: vertex){
		parent[x] = x;
		sz[x] = 1;
	}
	sort(edges.begin(), edges.end());
	int sum = 0;
	for(auto x: edges){
		int ru = find_root(x.u);
		int rv = find_root(x.v);
		if(ru == rv){
			unused.emplace_back(x);
			continue;
		}
		unite(ru, rv);
		adj2[ru].emplace_back(rv, x.w);
		adj2[rv].emplace_back(ru, x.w);
		sum = sum + x.w;
	}
	level[0] = 1;
	// dfs in MST
	dfs(get_id(1, 1), 0);
	for(int state=1; state<=19; ++state){
		for(auto x: vertex){
			lift[x][state].first = lift[lift[x][state - 1].first][state - 1].first;
			lift[x][state].second = max(lift[x][state - 1].second, lift[lift[x][state - 1].first][state - 1].second);
		}
	}
	int answer = 1e9;
	for(auto x: unused){
		int u = x.u, v = x.v;
		int maxx = 0;
		if(level[u] > level[v]){
			swap(u, v);
		}
		for(int state=19; state>=0; --state){
			if(level[lift[v][state].first] < level[u]){
				continue;
			}
			maxx = max(maxx, lift[v][state].second);
			v = lift[v][state].first;
		}
		if(u != v){
			for(int state=19; state>=0; --state){
				if(lift[v][state].first != lift[u][state].second){
					continue;
				}
				maxx = max({maxx, lift[u][state].second, lift[v][state].second});
				u = lift[u][state].first;
				v = lift[v][state].first;
			}
			maxx = max({maxx, lift[u][0].second, lift[v][0].second});
		}
		answer = min(answer, -maxx + x.w);
	}
	cout << answer;
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
