/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi18_gecko
 * ALGO		: Dijkstra
 * DATE		: 3 Sep 2022
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
	bool operator < (const Node& o) const {
		return w > o.w;
	}
	Node(int _v, ll _w): v(_v), w(_w) {}
};

const int MxN = 20020;
priority_queue<Node> pq;
vector<pair<int, ll>> adj[MxN];
int gecko[MxN], parent[MxN], deg[MxN];
ll w, dist[MxN];

inline void solution(){
	int n, m, k, p;
	cin >> n >> m >> k >> p;
	p++;
	for(int i=1; i<=k; ++i){
		cin >> gecko[i];
		gecko[i]++;
	}
	for(int i=1, u, v; i<=m; ++i){
		cin >> u >> v >> w;
		u++, v++;
		adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	dist[p] = 0;
	pq.emplace(p, 0);
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		for(auto x: adj[now.v]){
			ll nxt = now.w + x.second;
			if(dist[x.first] > nxt){
				parent[x.first] = now.v;
				pq.emplace(x.first, dist[now.v] = nxt);
				deg[x.first]++;
			}
		}
	}
	dbg(to_string(deg, 1, n));
	queue<int> q;
	q.emplce(p);
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(auto x: adj[now]){
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
