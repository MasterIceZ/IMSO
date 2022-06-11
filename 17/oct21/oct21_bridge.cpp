/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: oct21_bridge
 * ALGO		: Dynamic Programming
 * DATE		: 14 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 3030;
int a[MxN], b[MxN];
int dp[2][MxN];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i){
		cin >> b[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(a[i] == b[j]){
				dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
			}
			else{
				dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
			}
		}
	}
	cout << dp[n % 2][n];
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
