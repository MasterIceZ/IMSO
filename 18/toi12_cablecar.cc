/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi12_cable car
 * ALGO		: Kruskal's Algorithm, Minimum Spanning Tree
 * DATE		: 29 June 2022
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
	int u, v;
	double w;
	bool operator < (const Edge& o) const {
		return w > o.w;
	}
	Edge(int a, int b, double c): u(a), v(b), w(c) {}
};

vector<Edge> edges;

template<size_t S> 
class disjoint_set{
private:
	int parent[S + 10], sz[S + 10];
public:
	int find_root(int u){
		int now = u;
		while(now != parent[now]){
			now = parent[now];
		}
		return now;
	}
	bool merge(int u, int v){
		int ru = find_root(u), rv = find_root(v);
		if(ru == rv){
			return true; // already same set
		}
		if(sz[ru] > sz[rv]){
			parent[rv] = ru;
			sz[ru] = sz[ru] + sz[rv];
		}
		else{
			parent[ru] = rv;
			sz[rv] = sz[ru] + sz[ru];
		}
		return true;
	}
	disjoint_set(){
		for(int i=1; i<=S; ++i){
			sz[i] = 1;
			parent[i] = i;
		}
	}
};

disjoint_set<2505> dsu;

inline void solution(){
	int n, m, s, d, u, v;
	double p, w;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}
	sort(edges.begin(), edges.end());
	cin >> s >> d >> p;
	for(auto x: edges){
		if(dsu.find_root(x.u) == dsu.find_root(x.v)){
			continue;
		}
		dsu.merge(x.u, x.v);
		if(dsu.find_root(s) == dsu.find_root(d)){
			cout << fixed << setprecision(0) << ceil(p / (x.w - 1.0));
			return ;
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
