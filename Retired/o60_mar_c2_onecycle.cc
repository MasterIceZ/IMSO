/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o60_mar_c2_onecycle
 * ALGO		: Lowest Common Ancestor
 * DATE		: 12 Jan 2023
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

struct Answer{
	int u, v, w;
	bool operator < (const Answer& o) const {
		if(u != o.u){
			return u < o.u;
		}
		if(v != o.v){
			return v < o.v;
		}
		return w < o.w;
	}
	Answer(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
};

const int MxN = 3030;
const int LG = 15;

vector<Edge> edges, in, out;
vector<Answer> answer;
vector<pair<int, int>> adj[MxN];
int parent[MxN], mem[MxN], level[MxN], lift[LG][MxN];

int find_root(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

void dfs(int u, int p, int l){
	level[u] = l;
	lift[0][u] = p;
	for(auto x: adj[u]){
		if(x.first == p){
			continue;
		}
		mem[x.first] = x.second + mem[u];
		dfs(x.first, u, l + 1);
	}
}

inline int lca(int u, int v){
	if(level[u] < level[v]){
		swap(u, v);
	}
	for(int state=LG-1; state>=0; --state){
		if(level[lift[state][u]] < level[v]){
			continue;
		}
		u = lift[state][u];
	}
	if(u == v){
		return u;
	}
	for(int state=LG-1; state>=0; --state){
		if(lift[state][u] == lift[state][v]){
			continue;
		}
		u = lift[state][u];
		v = lift[state][v];
	}
	return lift[0][u];
}

inline int get_dist(int u, int v){
	return mem[u] + mem[v] - 2 * mem[lca(u, v)];
}

inline void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		for(int j=1, x; j<=n; ++j){
			if(i == j){
				continue;
			}
			cin >> x;
			if(i < j){
				edges.emplace_back(i, j, x);
			}
		}
	}
	sort(edges.begin(), edges.end());
	iota(parent + 1, parent + n + 1, 1);
	for(auto x: edges){
		int ru = find_root(x.u), rv = find_root(x.v);
		if(ru == rv){
			out.emplace_back(x);
		}
		else{
			parent[ru] = rv;
			in.emplace_back(x);
		}
	}
	for(auto x: in){
		adj[x.u].emplace_back(x.v, x.w);
		adj[x.v].emplace_back(x.u, x.w);
	}
	dfs(1, 0, 1);
	for(int state=1; state<LG; ++state){
		for(int i=1; i<=n; ++i){
			lift[state][i] = lift[state - 1][lift[state - 1][i]];
		}
	}
	for(auto x: out){
		if(get_dist(x.u, x.v) != x.w){
			in.emplace_back(x);
			break;
		}
	}
	for(auto x: in){
		answer.emplace_back(x.u, x.v, x.w);
	}
	sort(answer.begin(), answer.end());
	for(auto x: answer){
		cout << x.u << " " << x.v << " " << x.w << "\n";
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
