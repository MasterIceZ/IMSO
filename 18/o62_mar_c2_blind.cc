/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Blind Ballot
 * ALGO		: Disjoint Set Union
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

struct Query{
	bool type;
	int a, b, c;
	Query(bool _type, int _a, int _b, int _c): type(_type), a(_a), b(_b), c(_c) {}
};

const int MxN = 20020;
int parent[MxN];
bitset<MxN> deg, ok, visited;
vector<int> adj[MxN], time_out;

int find_root(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

void dfs(int u, int p){
	visited[u] = true;
	for(auto x: adj[u]){
		if(x == p || visited[x]){
			continue;
		}
		dfs(x, u);
	}
	time_out.emplace_back(u);
}

inline void solution(){
	int n, w;
	cin >> n >> w;
	for(int i=1; i<=n; ++i){
		parent[i] = i;
	}
	vector<Query> quries;
	for(int i=1, o, a, b, c, ra, rb, rc; i<=w; ++i){
		cin >> o >> a >> b >> c;
		if(o == 3){
			ra = find_root(a), rb = find_root(b), rc = find_root(c);
			parent[rb] = ra;
			parent[rc] = ra;
		}
		else{
			quries.emplace_back(o == 1, a, b, c);
		}
	}
	for(auto x: quries){
		int a = find_root(x.a), b = find_root(x.b), c = find_root(x.c);
		if(x.type){
			adj[b].emplace_back(a);
			adj[c].emplace_back(a);
			deg[a] = true;
		}
		else{
			adj[a].emplace_back(b);
			adj[a].emplace_back(c);
			deg[b] = true;
			deg[c] = true;
		}
		ok[a] = ok[b] = ok[c] = true;
	}
	for(int i=1; i<=n; ++i){
		if(!ok[i] || deg[i]){
			continue;
		}
		dfs(i, 0);
	}
	for(int i=1; i<=n; ++i){
		adj[i].clear();
	}
	reverse(time_out.begin(), time_out.end());
	for(int i=1; i<=n; ++i){
		adj[find_root(i)].emplace_back(i);
	}
	cout << time_out.size() << "\n";
	for(auto x: time_out){
		cout << adj[x].size() << " ";
		for(auto y: adj[x]){
			cout << y << " ";
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
