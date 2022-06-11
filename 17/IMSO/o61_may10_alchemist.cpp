/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o61_may10_alchemist
 * ALGO		: Depth First Search
 * DATE		: 13 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif
using ll = long long;
vector<int> adj[1010];
int hei[1010], maxx = -1;
int have[1010][66], current[66];
void dfs(int u, int p){
	hei[u] = p;
	maxx = max(maxx, p);
	for(auto x: adj[u]){
		dfs(x, p + 1);
	}
}
void solve(){
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	for(int i=2, a, b; i<=n; ++i){
		cin >> a >> b;
		adj[b].push_back(a);
	}
	dfs(0, 1);
	for(int i=0; i<n; ++i){
		hei[i] = maxx - hei[i];
	}
	for(int i=0, x; i<m; ++i){
		cin >> x;
		for(int j=1, a; j<=x; ++j){
			cin >> a;
			have[i][hei[a]] += 1;
		}
	}
	while(q--){
		int x;
		memset(current, 0, sizeof current);
		cin >> x;
		for(int i=1, a; i<=x; ++i){
			cin >> a;
			for(int j=0; j<60; ++j){
				current[j] += have[a][j];
			}
		}
		bool ok = false;
		for(int i=0; i<maxx; ++i){
			if(current[i] % 2){
				cout << i;
				ok = true;
				break;
			}
			current[i + 1] += current[i] >> 1;
		}
		if(!ok){
			cout << maxx - 1;
		}
		cout << "\n";
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

