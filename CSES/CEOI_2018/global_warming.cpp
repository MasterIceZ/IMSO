/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Global Warming
 * ALGO		: 
 * DATE		: 9 Jan 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int MxN = 200200;
int a[MxN], dp[MxN], lis[MxN];
int dp2[MxN], b[MxN];

void solve(){
	int answer = 0, sz = 0, n, x;
	cin >> n >> x;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	if(n <= 1000){
		dp[1] = 1;
		for(int i=2; i<=n; ++i){
			dp[i] = 1;
			for(int j=i-1; j>=1; --j){
				if(a[i] > a[j]){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			answer = max(answer, dp[i]);
		}
		dbg(to_vector(dp, 1, n));
		dp2[n] = 1;
		for(int i=n-1; i>=1; --i){
			dp2[i] = 1;
			for(int j=i+1; j<=n; ++j){
				if(a[i] < a[j]){
					dp2[i] = max(dp2[i], dp2[j] + 1);
				}
			}
		}
		dbg(to_vector(dp2, 1, n));
		for(int i=1; i<=n; ++i){
			for(int j=i+1; j<=n; ++j){
				if(a[i] - a[j] < x){
					answer = max(answer, dp[i] + dp2[j]);
				}
			}
		}
		cout << answer;
		return ;
	}
	for(int i=1; i<=n; ++i){
		int idx = lower_bound(lis, lis + sz, a[i]) - dp;
		lis[idx] = a[i];
		if(idx == sz){
			sz++;
		}
	}
	cout << sz;
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
