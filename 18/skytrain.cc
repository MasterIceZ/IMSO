/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: skytrain 
 * ALGO		: Dijkstra
 * DATE		: 26 Sep 2022
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
	Node(int _v, ll _w, int _state):
		v(_v), w(_w), state(_state) {}
};

const int MxN = 100010;
vector<pair<int, ll>> adj[MxN];
ll dist[MxN][4];
priority_queue<Node> pq;

inline void solution(){
	int n, m, s, e, u, v;
	ll w, k, nxt;
	cin >> n >> m >> s >> e >> k;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i=1; i<=n; ++i){
		dist[i][0] = dist[i][1] = dist[i][2] = 1e18 + 10ll;
	}
	dist[s][0] = 0ll;
	pq.emplace(s, 0ll, 0);
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			if(now.state == 0){
				nxt = k + now.w;
				if(dist[x.first][1] > nxt){
					pq.emplace(x.first, dist[x.first][1] = nxt, 1);
				}
				nxt = now.w + x.second;
				if(dist[x.first][0] > nxt){
					pq.emplace(x.first, dist[x.first][0] = nxt, 0);
				}
			}
			else if(now.state == 1){
				nxt = k + now.w;
				if(dist[x.first][1] > nxt){
					pq.emplace(x.first, dist[x.first][1] = nxt, 1);
				}
				nxt = now.w + x.second;
				if(dist[x.first][2] > nxt){
					pq.emplace(x.first, dist[x.first][2] = nxt, 2);
				}
			}
			else{
				nxt = now.w + x.second;
				if(dist[x.first][2] > nxt){
					pq.emplace(x.first, dist[x.first][2] = nxt, 2);
				}
			}
		}
	}
	ll res = 1e18 + 10ll;
	for(int i=0; i<3; ++i){
		dbg(dist[e][i]);
		if(dist[e][i] < 1e18 + 10){
			res = min(res, dist[e][i]);
		}
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
