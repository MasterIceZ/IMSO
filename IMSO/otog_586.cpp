/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: size of subtree
 * ALGO		: Dynamic Programming on Tree
 * DATE		: 17 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int dp[500500];
bitset<500500> visited;
vector<int> adj[500500];

void dfs(int u, int p){
	dp[u] = 1;
	visited[u] = true;
	for(auto x: adj[u]){
		if(x == p || visited[x]){
			continue;
		}
		dfs(x, u);
		dp[u] += dp[x];
	}
}

void solve(){
	int n, u, v;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		u++, v++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for(int i=1; i<=n; ++i){
		cout << dp[i] << " " ;
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
