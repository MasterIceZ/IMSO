/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: ぼっち・ざ・ろっく
 * ALGO		: Dijkstra
 * DATE		: 13 Jan 2023
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

struct State{
	int v;
	ll w;
	bool operator < (const State& o) const {
		return w > o.w;
	}
	State(int _v, ll _w):
		v(_v), w(_w) {}
};

const int MxN = 100010;
vector<pair<int, ll>> adj[MxN];
ll w, dist[MxN];
priority_queue<State> pq;

inline void solution(){
	int n, m, k;
	cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v >> w;
		u++, v++;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	int stp = n + 1;
	cin >> k;
	for(int i=1, u, w; i<=k; ++i){
		cin >> u >> w;
		u++;
		adj[stp].emplace_back(u, w);
		adj[u].emplace_back(stp, w);
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(stp, dist[stp] = 0);
	while(!pq.empty()){
		State now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			ll nxt = now.w + x.second;
			if(dist[x.first] > nxt){
				pq.emplace(x.first, dist[x.first] = nxt);
			}
		}
	}
	cout << dist[1];
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
