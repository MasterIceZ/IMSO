/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: ath12_earth crack
 * ALGO		: Dynamic Programming
 * DATE		: 12 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 505;
int a[MxN][MxN], dp[MxN][MxN];

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> a[i][j];
		}
	}
	memset(dp, 0x3f, sizeof dp);
	memset(dp[0], 0, sizeof dp[0]);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]}) + a[i][j];
		}
	}
	int answer = 1e9 + 100;
	for(int i=1; i<=m; ++i){
		answer = min(answer, dp[n][i]);
	}
	cout << answer;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
