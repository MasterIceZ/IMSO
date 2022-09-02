/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: subway (recommended by ItzMeOwww)
 * ALGO		: Floyd Warshall
 * DATE		: 8 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1000100;
vector<int> adj[MxN];
int dist[555][555];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		for(int j=1; j<=m; ++j){
			dist[i][j] = 1e9;
		}
	}
	for(int i=1, s; i<=m; ++i){
		cin >> s;
		for(int j=1, x; j<=s; ++j){
			cin >> x;
			adj[x].push_back(i);
		}
		dist[i][i] = 0;
	}
	for(int k=1; k<=n; ++k){
		for(auto u: adj[k]){
			for(auto v: adj[k]){
				if(u == v){
					continue;
				}
				dist[u][v] = 1;
			}
		}
	}
	for(int k=1; k<=m; ++k){
		for(int i=1; i<=m; ++i){
			for(int j=1; j<=m; ++j){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int q, a, b;
	cin >> q;
	while(q--){
		cin >> a >> b;
		int current_answer = 1e9;
		for(auto u: adj[a]){
			for(auto v: adj[b]){
				current_answer = min(current_answer, dist[u][v]);
			}
		}
		cout << (current_answer == 1e9 ? "impossible": to_string(current_answer)) << "\n";
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
