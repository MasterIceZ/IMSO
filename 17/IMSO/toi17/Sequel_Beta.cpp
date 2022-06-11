/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: toi17_sequel
 * ALGO		: Dynamic Programming, Square Root Decomposition
 * DATE		: 29 Dec 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#include "template.hpp"
#else
#define dbg(...) 0
#endif

using ll = long long;

const int SQ = 320;
int a[100100];
int dp[320][100100];

void solve(){
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int sq = sqrt(n);
	for(int i=1; i<=sq; ++i){
		for(int j=1; j<=n; ++j){
			dp[i][j] = dp[i][max(0, j - i)] + a[j];
		}
	}
	while(q--){
		int l, m, r;
		cin >> l >> m >> r;
		r = r - (r - l) % m;
		if(m <= sq){
			cout << dp[m][r] - dp[m][max(0, l - m)];
		}
		else{
			int ans = 0;
			for(int i=l; i<=r; i+=m){
				ans += a[i];
			}
			cout << ans;
		}
		cout << " ";
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
