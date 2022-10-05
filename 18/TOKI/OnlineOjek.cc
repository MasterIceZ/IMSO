/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Online Ojek
 * ALGO		: DIjkstra
 * DATE		: 30 Sep 2022
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

struct Adj{
	int v;
	ll w;
	bool local;
	Adj(int _v, ll _w, bool _local):
		v(_v), w(_w), local(_local) {}
};

const int MxN = 110;
priority_queue<Node> pq;
vector<Adj> adj[MxN];
ll dist[MxN]; // (city)

inline void solution(){
	int u, v, w, n, m, stp, edp;
	ll c_d, m_d, c_p, m_p, t;
	cin >> n >> m >> c_d >> m_d >> c_p >> m_p >> stp >> edp;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w >> t;
		adj[u].emplace_back(v, w, t);
		adj[v].emplace_back(u, w, t);
	}
	memset(dist, 0x3f, sizeof dist);
	dist[stp][0] = 0ll;
	pq.emplace(stp, 0ll);
	while(!pq.empty()){
		Node now = pq.top(); pq.pop();
		if(now.w >= dist[now.v]){
			continue;
		}
		if(now.v == edp){
			cout << now.w;
			return ;
		}
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	string subtasks;
	cin >> subtasks;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
