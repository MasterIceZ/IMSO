/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: crystal
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

const int MxN = 10100;
const int MOD = 10001;
int dp[MxN];

void solve(){
	int n;
	cin >> n;
	dp[0] = 1;
	for(int i=1; i<=n; ++i){
		for(int j=0; j<i; ++j){
			dp[i] += (dp[j] * dp[i - j - 1]);
			dp[i] %= MOD;
		}
	}
	cout << dp[n];
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
