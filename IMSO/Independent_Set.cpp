/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: P-Independent Set
 * ALGO		: Dynamic Programming on Tree
 * DATE		: 7 Feb 2022
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
const ll MOD = 1e9 + 7;

vector<int> adj[MxN];
// (white, black)
ll dp[MxN][3];

void dfs(int u, int p){
	dp[u][0] = dp[u][1] = 1;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
		dp[u][0] = (dp[u][0] * (dp[x][0] + dp[x][1])) % MOD;
		dp[u][1] = (dp[u][1] * dp[x][0]) % MOD;
	}
//	for(auto x: adj[u]){
//		if(x == p){
//			continue;
//		}
//	}
}

void solve(){
	int n, u, v;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	u = 1;
	cout << (dp[u][0] + dp[u][1]) % MOD ;
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
