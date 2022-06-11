/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 2ndshort
 * ALGO		: Dijkstra
 * DATE		: 20 Jan 2022
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
	int v, w, state;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

const int MxN = 10100;
vector<pair<int, int>> adj[MxN];
int dist[MxN][3];

void solve(){
	int n, m, s, t, u, v, w;
	cin >> n >> m >> s >> t;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	dist[s][0] = 0;
	priority_queue<Node> pq;
	pq.push({s, 0, 0});
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.state == 1 && now.v == t){
			cout << now.w;
			return ;
		}
		for(auto x: adj[now.v]){
			int nxt = x.second + now.w;
			if(now.state == 0){
				if(dist[x.first][now.state] > nxt){
					dist[x.first][now.state] = nxt;
					pq.push({x.first, nxt, now.state});
				}
				else if(dist[x.first][now.state + 1] > nxt){
					dist[x.first][now.state + 1] = nxt;
					pq.push({x.first, nxt, now.state + 1});
				}
			}
			else{
				if(dist[x.first][now.state] > nxt){
					dist[x.first][now.state] = nxt;
					pq.push({x.first, nxt, now.state});
				}
			}
		}
	}
	cout << dist[t][1];
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
