/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
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
vector<int> adj[MxN];
int a[MxN], dp[2][MxN];

void dfs(int u, int p){
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
		dp[0][u] += max(dp[0][x], dp[1][x]);
		dp[1][u] += dp[0][x];
	}
	dp[1][u] += a[u];
}

void solve(){
	int n, u, v;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, -1);
	cout << max(dp[0][0], dp[1][0]);
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
