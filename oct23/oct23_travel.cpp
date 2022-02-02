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

int level[MxN];
pair<int, int> dp[MxN][16];

void dfs(int u, int p, int lv){
	level[u] = lv;
	dp[u][0].first = p;
	for(auto x: adj[u]){
		if(x == p){
			continue;
		}
		dp[x][0].second = 1;
		dfs(x, u, lv + 1);
	}
}

int lca(int u, int v){
	int res = 0;
	if(level[u] > level[v]){
		swap(u, v);
	}
	for(int state=15; state>=0; --state){
		if(level[u] > level[dp[v][state].first]){
			continue;
		}
		v = dp[v][state].first;
		res += dp[v][state].second;
	}
	if(u == v){
		return res;
	}
	for(int state=15; state>=0; --state){
		if(dp[u][state].first != dp[v][state].first){
			u = dp[u][state].first;
			v = dp[v][state].first;
			res += dp[u][state].second + dp[v][state].second;
		}
	}
	return res + dp[u][0].second + dp[v][0].second;
}

void solve(){
	int n, u, v, q, x;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1, 0, 1);
	for(int state=1; state<=15; ++state){
		for(int i=1; i<=n; ++i){
			dp[i][state].first = dp[dp[i][state - 1].first][state - 1].first;
			dp[i][state].second = dp[i][state - 1].second + dp[dp[i][state - 1].first][state - 1].second;
		}
	}
	cin >> q;
	u = 1;
	int answer = 0;
	while(q--){
		cin >> v;
		answer += lca(u, v);
		u = v;
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
