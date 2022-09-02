/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: o59_may05_boxes
 * ALGO		: Dynamic Programming
 * DATE		: 14 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

int dp[333][333];

int divide(int l, int r){
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	if(l == r){
		return dp[l][r] = 1;
	}
	int res = 0;
	for(int i=l; i<r; ++i){
		int cur = divide() + divide();
		res = max(res, );
	}
	return dp[l][r] = res;
}

void solve(){
	memset(dp, -1, sizeof dp);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	cout << divide(1, n);
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
