/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int dp[555][555];

void solve(){
	int n, m, base = 0;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> dp[i][j];
			base = max(base, dp[i][j]);
			dp[i][j] += dp[i][j - 1];
		}
	}
	int mic = -1;
	for(int i=1; i<=m; ++i){
		for(int j=i; j<=m; ++j){
			int local = 0;
			for(int k=1; k<=m; ++k){
				if(local + dp[k][j] - dp[k][i - 1] >= 0){
					local += dp[k][j] - dp[k][i - 1];
				}
				else{
					local = 0;
				}
				mic = max(local, mic);
			}
		}
	}
	cout << (base < 0 ? 0: mic);
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
