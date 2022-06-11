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

const int MxN = 303;
int a[2 * MxN][2 * MxN];
int dp[2 * MxN];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=2*n; ++i){
		for(int j=1; j<=2*n; ++j){
			cin >> a[i][j];
		}
	}
	memset(dp, 0x3f, sizeof dp);
	dp[2] = 0;
	for(int i=3; i<=2*n; ++i){
		for(int j=2; j<i; ++j){
			dp[i] = min(dp[i], a[i][j] + dp[j]);
		}
	}
	cout << dp[2 * n];
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
