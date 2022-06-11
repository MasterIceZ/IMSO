/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: elephant
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

const int MxN = 100100;
int dp[MxN], a[MxN];

void solve(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	for(int i=3; i<=n; ++i){
		dp[i] = max(a[i] + dp[i - 3], dp[i - 1]);
		dbg(dp[i]);
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
