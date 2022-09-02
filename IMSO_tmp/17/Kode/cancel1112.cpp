/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Cancel 1112
 * ALGO		: Folyd Warshall
 * DATE		: 22 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 550;
ll dist[MxN][MxN];
ll p[MxN];

void solve(){
	int n, m;
	cin >> n >> m;
	memset(dist, 0x3f, sizeof dist);
	for(int i=1; i<=n; ++i){
		dist[i][i] = 0;
		cin >> p[i];
	}
	int u, v;
	ll w;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = min(dist[u][v], w);
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	ll res = LLONG_MAX;
	int answer = -1;
	for(int i=1; i<=n; ++i){
		ll current = 0;
		for(int j=1; j<=n; ++j){
			if(i == j){
				continue;
			}
			current += (p[j] * dist[i][j]);
		}
		if(current < res){
			res = current;
			answer = i;
		}
	}
	cout << answer << " " << res ;
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
