/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: highway
 * ALGO		: Depth First Search
 * DATE		: 28 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 100100;

bitset<MxN> closed;

struct Directed_Graph{
	vector<int> adj[MxN];
	bitset<MxN> visited;
	void add_edge(int u, int v){
		adj[u].emplace_back(v);
	}
	void dfs(int u, int p){
		visited[u] = true;
		for(auto x: adj[u]){
			if(x == p || closed[x] || visited[x]){
				return ;
			}
			dfs(x, u);
		}
	}
} adj, rev;

void solve(){
	int n, m, q, x, y, u, v;
	cin >> n >> m >> q;
	for(int i=1; i<=m; ++i){
		cin >> u >> v;
		adj.add_edge(u, v);
		rev.add_edge(v, u);
	}
	stack<pair<int, int>> query;
	for(int i=1; i<=q; ++i){
		cin >> x >> y;
		query.emplace(x, y);
		if(x == 1){
			closed[y] = true;
		}
	}
	adj.dfs(1, 0);
	rev.dfs(n, 0);
	stack<int> answer;
	while(!query.empty()){
		pair<int, int> now = query.top();
		query.pop();
		if(now.first == 1){
			closed[now.second] = false;
			for(auto x: rev.adj[now.second]){
				if(!adj.visited[x]){
					continue;
				}
				adj.dfs(x, 0);
			}
			for(auto x: adj.adj[now.second]){
				if(!rev.visited[x]){
					continue;
				}
				rev.dfs(x, 0);
			}
		}
		else{
			answer.push(adj.visited[now.second] && rev.visited[now.second]);
		}
	}
	while(!answer.empty()){
		cout << answer.top() << "\n";
		answer.pop();
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
	}
	return 0;
}
