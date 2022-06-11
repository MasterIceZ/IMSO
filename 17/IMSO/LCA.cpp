/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: LCA
 * ALGO		: Lowest Common Ancestor
 * DATE		: 29 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1010;
const int LG = 15;
vector<int> adj[MxN];
int in[MxN], level[MxN], dp[LG][MxN];

void dfs(int u, int p){
	level[u] = level[p] + 1;
	dp[0][u] = p;
	for(auto x: adj[u]){
		dfs(x, u);
	}
}

void solve(){
	int q, n;
	cin >> n;
	for(int i=1, m, x; i<=n; ++i){
		cin >> m;
		while(m--){
			cin >> x;
			adj[i].push_back(x);
			in[x]++;
		}
	}
	for(int i=1; i<=n; ++i){
		if(in[i] == 0){
			dfs(i, 0);
		}
	}
	for(int state=1; state<LG; ++state){
		for(int i=1; i<=n; ++i){
			dp[state][i] = dp[state - 1][dp[state - 1][i]];
		}
	}
	cin >> q;
	while(q--){
		int u, v;
		cin >> u >> v;
		if(level[u] > level[v]){
			swap(u, v);
		}
		for(int state=LG-1; state >= 0; --state){
			if(level[u] > level[dp[state][v]]){
				continue;
			}
			v = dp[state][v];
		}
		if(u == v){
			cout << v << "\n";
			continue;
		}
		for(int state=LG-1; state >= 0; --state){
			if(dp[state][u] != dp[state][v]){
				u = dp[state][u];
				v = dp[state][v];
			}
		}
		cout << dp[0][u] << "\n";
	}
	for(int i=1; i<=n; ++i){
		adj[i].clear();
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1, it = 1;
	cin >> q;
	while(q--){
		cout << "Case " << it << ":\n";
		solve();
	}
	return 0;
}
