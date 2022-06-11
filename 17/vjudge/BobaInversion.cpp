/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Boba Inversion
 * ALGO		: Dynamic Programming
 * DATE		: 7 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 5050;
ll a[MxN], dp[MxN][MxN];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=1; i<n; ++i){
		dp[i][i + 1] = (a[i] > a[i + 1]);
	}
	for(int i=1; i<=n; ++i){
		for(int j=i+2; j<=n; ++j){
		}
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			cout << dp[i][j] << " " ;
		}
		cout << "\n";
	}
	int q, l, r;
	cin >> q;
	while(q--){
		cin >> l >> r;
		cout << dp[l][r] << "\n";
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
