/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Travel
 * ALGO		: Breadth First Search
 * DATE		: 19 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 30030;
vector<int> adj[MxN];
queue<int> q;
int dist[MxN];

int dijkstra(int source, int sink){
	while(!q.empty()){
		q.pop();
	}
	memset(dist, -1, sizeof dist);
	q.push(source);
	dist[source] = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(now == sink){
			return dist[now];
		}
		for(auto x: adj[now]){
			if(dist[x] != -1){
				continue;
			}
			dist[x] = dist[now] + 1;
			q.push(x);
		}
	}
	return dist[sink];
}

void solve(){
	int n, u, v, q, x;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> q;
	int source = 1;
	int answer = 0;
	while(q--){
		cin >> x;
		answer += dijkstra(source, x);
		source = x;
	}
	cout << answer;
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
