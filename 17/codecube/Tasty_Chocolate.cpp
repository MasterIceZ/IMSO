/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Tasty Chocolate
 * ALGO		: Dynamic Programming 
 * DATE		: 10 Feb 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 1010;
int dp[MxN][3030], a[MxN];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		dp[i][0] = 1e9 + 100;
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=3000; ++j){
			dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + (a[i] != j));
		}
	}
	cout << dp[n][3000];
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
