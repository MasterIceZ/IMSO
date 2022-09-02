/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Factorial Approximation
 * ALGO		: Dynamic Programming
 * DATE		: 25 Dec 2021
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
ll dp[MxN];

void solve(){
	int n;
	cin >> n;
	cout << dp[n];
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	ll cnt;
	double current = 1;
	dp[0] = 1;
	for(ll i=1; i<=100000; ++i){
		current *= i;
		cnt = 0;
		while(current >= 10){
			cnt++;
			current /= 10;
		}
		dp[i] = dp[i - 1] + cnt;
	}
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
