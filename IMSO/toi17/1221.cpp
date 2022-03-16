/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: 1221
 * ALGO		: Floyd Warshall
 * DATE		: 23 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int a[505], dist[505][505], cnt[505][505];

void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			dist[i][j] = a[i] + a[j];
			cnt[i][j] = 2;
		}
	}
	for(int i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = min(dist[u][v], w);
		cnt[u][v] = 2;
	}
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					cnt[i][j] = cnt[i][k] + cnt[j][k];
				}
				else if(dist[i][k] + dist[k][j] == dist[i][j]){
					cnt[i][j] = max(cnt[i][j], cnt[i][k] + cnt[k][j]);
				}
			}
		}	
	}
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << dist[a][b] << " " << cnt[a][b] << "\n";
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
