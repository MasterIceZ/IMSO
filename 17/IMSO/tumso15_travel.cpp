/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: tumso15_travel
 * ALGO		: Dynamic Programming
 * DATE		: 2 Jan 2022
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
const int MOD = 1e9 + 7;
int dp[MxN][6];

void solve(){
	int n;
	cin >> n;
	assert(n <= 1000000);
	cout << dp[n][1];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	dp[0][1] = 1;
	for(int i=1; i<=1000000; ++i){
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][4]) % MOD;
		dp[i][3] = (dp[i - 1][1] + dp[i - 1][5]) % MOD;
		dp[i][4] = (dp[i - 1][2] + dp[i - 1][5]) % MOD;
		dp[i][5] = (dp[i - 1][4] + dp[i - 1][3]) % MOD;
	}
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
