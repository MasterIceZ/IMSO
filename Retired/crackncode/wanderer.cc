/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Wanderer
 * ALGO		: Dijkstra
 * DATE		: 12 May 2023
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

struct Node{
	int v;
	ll w;
	int state;
	Node(int _v, ll _w, int _state):
		v(_v), w(_w), state(_state) {}
	bool operator < (const Node& o) const {
		return w > o.w;
	}
};

const int MxN = 100010;
ll dist[11][MxN], w;
vector<pair<int, ll>> adj[MxN];
priority_queue<Node> pq;

inline void solution(){
	int n, m, q, u, v;
	cin >> n >> m >> q;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(1, dist[0][1] = 0, 0);
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			ll nxt = now.w;
			int nxt_state = q - 1;
			if(now.state == 0 && dist[q - 1][x.first] > nxt){
				pq.emplace(x.first, dist[q - 1][x.first] = nxt, q - 1);
			}
			nxt += x.second;
			nxt_state = max(0, q - 1);
			if(dist[nxt_state][x.first] > nxt){
				pq.emplace(x.first, dist[nxt_state][x.first] = nxt, nxt_state);
			}
		}
	}
	ll res = LLONG_MAX;
	for(int i=0; i<=q; ++i){
		res = min(res, dist[i][n]);
	}
	cout << res;
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
