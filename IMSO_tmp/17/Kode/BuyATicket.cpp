/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Buy A Ticket
 * ALGO		: Dijkstra
 * DATE		: 21 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

struct Node{
	int v;
	ll w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

void solve(){
	ll w;
	int n, m, u, v;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		w *= 2;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i=1; i<=n; ++i){
		cin >> dist[i];
	}
	priority_queue<Node> pq;
	for(int i=1; i<=n; ++i){
		pq.push({dist[i], i});
	}
	while(!pq.empty()){
		Node now = pq.top();
		pq.top();
		if(dist[now.first] != now.w){
			continue;
		}
		for(auto x: adj[now.v]){
			int nxt = dist[x.first] + x.second;
			
		}
	}
	for(int i=1; i<=n; ++i){
		cout << dist[i] << " ";
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
