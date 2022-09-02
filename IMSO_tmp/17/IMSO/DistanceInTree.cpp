/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Distance in Tree
 * ALGO		: Dynamic Programming on Tree
 * DATE		: 8 Feb 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 50500;
vector<int> adj[MxN];
int dp[MxN][555], dp2[MxN][3], n, k;

void dfsSum(int u, int p){
	dp[u][0] = 1;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfsSum(x, u);
		for(int state=1; state<=k; ++state){
			dp[u][state] += dp[x][state - 1];
		}
	}
}

void dfs(int u, int p){
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
		dp2[u][0] = dp[u][k];
		for(int state=1; state<k; ++state){
			dp2[u][1] += dp[u][state - 1] * (dp[u][k - state] - dp[x][k - state - 1]);
		}
	}
}

void solve(){
	cin >> n >> k;
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfsSum(1, 0);
	dfs(1, 0);
	int res = 0;
	for(int i=1; i<=n; ++i){
		res +=  dp2[i][0] + dp2[i][1] / 2;
	}
	cout << res;
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
