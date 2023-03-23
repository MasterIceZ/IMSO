/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi15_budget
 * ALGO		: Minimum Spanning Tree
 * DATE		: 20 Mar 2023
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
	ll w;
	bool operator < (const Edge & o) const {
		return w < o.w;
	}
	Edge(int _u, int _v, ll _w):
		u(_u), v(_v), w(_w) {}
};

const int MxP = 300030;
const int MxB = 3030;
vector<Edge> edges;
pair<int, ll> c[MxP];
int len[MxP], parent[MxB];
ll cost[MxP], sum;

int find_root(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

inline void solution(){
	int b, e, p;
	cin >> b >> e;
	for(int i=1; i<=b; ++i){
		parent[i] = i;
	}
	for(int i=1, u, v, w, t; i<=e; ++i){
		cin >> u >> v >> w >> t;
		edges.emplace_back(u, v, t ? 0: w);
	}
	cin >> p;
	for(int i=1; i<=p; ++i){
		cin >> c[i].first >> c[i].second;
	}
	sort(c + 1, c + p + 1);
	for(int i=p-1; i>=1; --i){
		c[i].second = min(c[i].second, c[i + 1].second);
		len[i] = c[i].first;
		cost[i] = c[i].second;
	}
	sort(edges.begin(), edges.end());
	for(auto x: edges){
		int ru = find_root(x.u), rv = find_root(x.v);
		if(ru == rv){
			continue;
		}
		int idx = lower_bound(len, len + p + 1, x.w) - len;
		ll add_cost = cost[idx];
		sum += add_cost;
		parent[ru] = rv;
	}
	cout << sum;
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
