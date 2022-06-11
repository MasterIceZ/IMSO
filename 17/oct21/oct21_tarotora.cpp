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
const int OS = 111;
const int INF = 1e9 + 100;
pair<int, int> a[MxN];
int dp[2][2 * OS];

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	memset(dp[0], 0x3f, sizeof dp[0]);
	dp[0][k] = 0;
	for(int i=1; i<=n; ++i){
		dp[i & 1][0] = min(INF, dp[i & 1 ^ 1][1] + a[i].second);
		dp[i & 1][2 * k] = min(INF, dp[i & 1 ^ 1][2 * k - 1] + a[i].first);
		for(int j=1; j<2*k; ++j){
			dp[i & 1][j] = INF;
			dp[i & 1][j] = min({dp[i & 1][j], dp[i & 1 ^ 1][j - 1] + a[i].first, dp[i & 1 ^ 1][j + 1] + a[i].second});
		}
		dbg(to_vector(dp[i & 1], 0, 2 * k));
	}
	int answer = 1e9 + 10;
	for(int i=0; i<=2*k; ++i){
		answer = min(answer, dp[n & 1][i]);
		dbg(dp[n & 1][i]);
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
