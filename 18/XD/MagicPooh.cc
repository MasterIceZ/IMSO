/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Magic Pooh
 * ALGO		: Dijkstra
 * DATE		: 22 Sep 2022
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
	int v, w, state;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int _v, int _w, int _state):
		v(_v), w(_w), state(_state) {}
};

const int MxN = 100010;
vector<pair<int, int>> adj[MxN];
priority_queue<Node> pq;
int dist[MxN][3];

inline void solution(){
	int n, m, k, t, u, v, w;
	cin >> n >> m >> k >> t;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	dist[1][0] = 0;
	pq.emplace(1, 0, 0);
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		if(now.v == n){
			if(now.w <= t){
				cout << "Happy Winnie the Pooh :3\n" << now.w;
				return ;
			}
			else{
				cout << "No Honey TT";
				return ;
			}
		}
		for(auto x: adj[now.v]){
			int nxt = now.w + x.second;
			if(dist[x.first][now.state] > nxt && nxt <= t){
				pq.emplace(x.first, dist[x.first][now.state] = nxt, now.state);
			}
			nxt = dist[now.v][now.state] + k;
			if(now.state == 0 && dist[x.first][now.state + 1] > nxt && nxt <= t){
				pq.emplace(x.first, dist[x.first][now.state + 1] = nxt, now.state + 1);
			}
		}
	}
	cout << "No Honey TT";
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
