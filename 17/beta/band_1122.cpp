/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: band
 * ALGO		: Math
 * DATE		: 5 Feb 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

bool adj[1010][1010];
int answer[10], a[5010], b[5010];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> a[i] >> b[i];
		adj[a[i]][b[i]] = adj[b[i]][a[i]] = true;
	}
	for(int i=1; i<=m; ++i){
		for(int j=i+1; j<=m; ++j){
			if(a[i] == a[j] || a[i] == b[j] || b[i] == a[j] || b[i] == b[j]){
				continue;
			}
			int cnt = 0;
			cnt += adj[a[i]][b[i]];
			cnt += adj[a[i]][a[j]];
			cnt += adj[a[i]][b[j]];
			cnt += adj[b[i]][a[j]];
			cnt += adj[b[i]][b[j]];
			cnt += adj[a[j]][b[j]];
			answer[cnt]++;
		}
	}
	cout << answer[5] / 2 + answer[6] / 3;
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
