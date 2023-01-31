/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Royal Parade
 * ALGO		: Dijkstra
 * DATE		: 1 Feb 2023
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
priority_queue<State> pq;
bitset<MxN> visited;

inline void dijkstra(int source, vector<ll>& dist){
	pq.emplace(source, dist[source] = 0);
	while(!pq.empty()){
		State now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			if(visited[x.first]){
				continue;
			}
			ll nxt = x.second + now.w;
			if(dist[x.first] > nxt){
				pq.emplace(x.first, dist[x.first] = nxt);
			}
		}
	}
}

inline void solution(){
	int n, m, u, v;
	ll w;
	cin >> n >> m;
	vector<vector<ll>> dist(3, vector<ll> (n + 1, (ll) 1e18 + 100));
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	dijkstra(a, dist[0]);
	dijkstra(b, dist[1]);
	for(int i=1; i<=n; ++i){
		if(dist[1][i] + dist[0][i] != dist[0][b]){
			continue;
		}
		visited[i] = true;
	}
	dijkstra(c, dist[2]);
	dbg(to_string(visited, 1, n));
	dbg(dist[2]);
	cout << (dist[2][d] >= 1e18 + 100 ? -1: dist[2][d]);
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
