/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: tumso16_ant
 * ALGO		: Lowest Common Ancestor
 * DATE		: 28 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1e5 + 10;
const int LG = 22;
vector<pair<int, ll>> adj[MxN];
int dp[LG][MxN], level[MxN];
ll dist[LG][MxN];

void dfs(int u, int p){
	level[u] = level[p] + 1;
	dp[0][u] = p;
	for(auto x: adj[u]){
		if(x.first == p){
			continue;
		}
		dist[0][x.first] = x.second;
		dfs(x.first, u);
	}
}

void solve(){
	int a, b;
	cin >> a >> b;
	a++, b++;
	ll answer = 0;
	if(level[a] > level[b]){
		swap(a, b);
	}
	for(int state=20; state>=0; --state){
		if(level[a] > level[dp[state][b]]){
			continue;
		}
		answer += dist[state][b];
		b = dp[state][b];
	}
	if(a == b){
		dbg(answer);
		cout << answer ;
		return ;
	}
	for(int state=20; state>=0; --state){
		if(dp[state][a] != dp[state][b]){
			dbg(state, a, dist[state][a], b, dist[state][b]);
			answer += dist[state][a] + dist[state][b];
			a = dp[state][a];
			b = dp[state][b];
		}
	}
	dbg(answer, dist[0][a], dist[0][b]);
	cout << answer + dist[0][a] + dist[0][b];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int n;
	ll w;
	cin >> n;
	for(int i=2, v; i<=n; ++i){
		cin >> v >> w;
		v++;
		adj[i].emplace_back(v, w);
		adj[v].emplace_back(i, w);
	}
	dfs(1, 0);
	for(int state=1; state < LG; ++state){
		for(int i=1; i<=n; ++i){
			dp[state][i] = dp[state - 1][dp[state - 1][i]];
			dist[state][i] = dist[state - 1][i] + dist[state - 1][dp[state - 1][i]];
		}
	}
	dbg(to_vector(level, 1, n));
	dbg(to_vector(dist[0], 1, n));
	dbg(to_vector(dist[1], 1, n));

	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
