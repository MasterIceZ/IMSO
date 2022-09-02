/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Longest Good Segment
 * ALGO		: Lowest Common Ancestor, Binary Lifting
 * DATE		: 3 Jan 2022
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
ll qs[MxN], answer[MxN], dp[MxN];

void solve(){
	int n, k; 
	ll s;
	cin >> n >> k >> s;
	for(int i=1; i<=n; ++i){
		cin >> qs[i];
		qs[i] += qs[i - 1];
	}
	for(int i=1; i<=n; ++i){
		int idx = upper_bound(qs, qs + n + 1, qs[i - 1] + s) - qs;
		dp[i] = idx;
		answer[i] = i;
	}
	dp[n + 1] = n + 1;
	int LG = __lg(n);
	for(int state=0; state<=LG; ++state){
		if(k & (1 << state)){
			for(int i=1; i<=n + 1; ++i){
				answer[i] = dp[answer[i]];
			}
		}
		for(int i=1; i<=n + 1; ++i){
			dp[i] = dp[dp[i]];
		}
	}
	ll maxx = 0;
	for(int i=1; i<=n; ++i){
		maxx = max(maxx, answer[i] - i);
	}
	cout << maxx;
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
