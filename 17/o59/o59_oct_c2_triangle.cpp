/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Triangle Art
 * ALGO		: Dynamic Programming
 * DATE		: 31 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MOD = 1e9 + 7;

int dp[111][111];
int n, k;

void add(int x, int y){
	for(int i=x-1; i>=1; --i){
		if(x - i > k){
			break;
		}
		dp[x][y] += dp[i - 1][y - 1] + 1;
		dp[x][y] %= MOD;
	}
	for(int i=y-1; i>=1; --i){
		if(y - i > k){
			break;
		}
		dp[x][y] += dp[x - 1][i - 1] + 1;
		dp[x][y] %= MOD;
	}
}

void solve(){
	cin >> n >> k;
	dp[2][1] = dp[1][2] = 1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(dp[i][j] != 0){
				continue;
			}
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			dp[i][j] %= MOD;
			add(i, j);
		}
	}
	cout << dp[n][n];
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
