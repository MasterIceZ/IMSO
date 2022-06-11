/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Distance Query
 * ALGO		: Lowest Common Ancestor
 * DATE		: 3 Jan 2022
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
const int LG = 20;
vector<pair<int, int>> adj[MxN];
int hei[MxN], dp[LG][MxN];
pair<int, int> answer[LG][MxN]; // (min, max)

void dfs(int u, int p){
	hei[u] = hei[p] + 1;
	dp[0][u] = p;
	for(auto x: adj[u]){
		if(x.first == p || hei[x.first]){
			continue;
		}
		answer[0][x.first].first = x.second;
		answer[0][x.first].second = x.second;
		dfs(x.first, u);
	}
}

void solve(){
	int n, u, v, w;
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for(int i=1; i<=n; ++i){
		if(!hei[i]){
			dfs(i, 0);
		}
	}
	for(int state=1; state<20; ++state){
		for(int i=1; i<=n; ++i){
			dp[state][i] = dp[state - 1][dp[state - 1][i]];
			answer[state][i].first = min(answer[state - 1][i].first, answer[state - 1][dp[state - 1][i]].first);
			answer[state][i].second = max(answer[state - 1][i].second, answer[state - 1][dp[state - 1][i]].second);
		}
	}
	int q;
	cin >> q;
	while(q--){
		int u, v, maxx = 0, minn = 1e9 + 100;
		cin >> u >> v;
		if(hei[u] > hei[v]){
			swap(u, v);
		}
		for(int state=19; state>=0; --state){
			if(hei[u] > hei[dp[state][v]]){
				continue;
			}
			minn = min(minn, answer[state][v].first);
			maxx = max(maxx, answer[state][v].second);
			v = dp[state][v];
		}
		if(u == v){
			cout << minn << " " << maxx << "\n";
			continue;
		}
		for(int state=19; state>=0; --state){
			if(dp[state][u] != dp[state][v]){
				minn = min({minn, answer[state][u].first, answer[state][v].first});
				maxx = max({maxx, answer[state][u].second, answer[state][v].second});
				u = dp[state][u];
				v = dp[state][v];
			}
		}
		cout << min({minn, answer[0][u].first, answer[0][v].first}) << " " << max({maxx, answer[0][u].second, answer[0][v].second}) << "\n";
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
