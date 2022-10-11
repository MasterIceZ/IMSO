/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Manga
 * ALGO		: Dijkstra, Binary Search
 * DATE		: 7 Oct 2022
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

struct Vertex{
	int v, w, t;
	Vertex(int _v, int _w, int _t):
		v(_v), w(_w), t(_t) {}
};

struct Node{
	int v, w;
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int _v, int _w):
		v(_v), w(_w) {}
};

const int MxN = 50050;
vector<Vertex> adj[MxN];
int n, m, k, dist[MxN];
priority_queue<Node> pq;

inline void dijkstra(int max_time){
	memset(dist, 0x3f, sizeof dist);
	pq.emplace(1, dist[1] = 0);
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			int nxt  = x.w + now.w;
			if(x.t > max_time || nxt > k){
				continue;
			}
			if(dist[x.v] > nxt){
				pq.emplace(x.v, dist[x.v] = nxt);
			}
		}
	}
	return ;
}

inline void solution(){
	cin >> n >> m >> k;
	for(int i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w, i);
		adj[v].emplace_back(u, w, i);
	}
	int l = 1, r = m;
	while(l < r){
		int mid = (l + r) >> 1;
		dijkstra(mid);
		if(dist[n] <= k){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	dijkstra(r);
	cout << (dist[n] <= k ? r: -1);
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
