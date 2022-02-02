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

const int MxN = 100100;
const int OS = 222;
pair<int, int> a[MxN];
int dp[MxN][OS];

void solve(){
	int n, k;
	cin >> n >> k;
	memset(dp, 0x3f, sizeof dp);
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	dp[0][k] = 0;
	for(int i=1; i<=n; ++i){
		dp[i][0] = dp[i - 1][1] + a[i].second;
		dp[i][2 * k] = dp[i - 1][2 * k - 1] + a[i].first;
		for(int j=1; j<2*k; ++j){
			dp[i][j] = min({dp[i][j], dp[i - 1][j - 1] + a[i].first, dp[i - 1][j + 1] + a[i].second});
		}
	}
	int answer = 1e9 + 10;
	for(int i=0; i<=2*k; ++i){
		answer = min(answer, dp[n][i]);
	}
	cout << answer;
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
