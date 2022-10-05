/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Long Way Home
 * ALGO		: Dijkstra
 * DATE		: 24 Sep 2022
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
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int _v, int _w, int _state): v(_v), w(_w), state(_state) {}
};

const int MxN = 100010;
vector<pair<int, ll>> adj[MxN];
priority_queue<Node> pq;
ll dist[MxN][22], w;

inline void solution(){
	int n, m, k, u, v;
	cin >> n >> m >> k;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(1, dist[1][0] = 0, 0);
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			ll nxt = now.w + x.second;
			if(dist[x.first][now.state] > nxt){
				pq.emplace(x.first, dist[x.first][now.state] = nxt, now.state);
			}
			nxt = now.w + (x.first - now.v) * (x.first - now.v);
			if(now.state + 1 <= k && dist[x.first][now.state + 1] > nxt){
				pq.emplace(x.first, dist[x.first][now.state + 1] = nxt, now.state);
			}	
		}
	}
	for(int i=1; i<=n; ++i){
		cout << *min_element(dist[i], dist[i] + k + 1) << " " ;
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
