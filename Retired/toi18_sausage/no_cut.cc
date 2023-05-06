#include <bits/stdc++.h>
using namespace std;

const int MxN = 5050;
int n, dp[MxN][MxN], D[MxN];

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> D[i];
	}
	for(int i=1; i<=n; ++i){
		dp[i][i] = D[i];
	}
	for(int sz=2; sz<=n; ++sz){
		for(int l=1; l+sz-1<=n; ++l){
			int r = l + sz - 1;
			dp[l][r] = abs(D[l] - D[r]) + max(dp[l + 1][r] + D[l], dp[l][r - 1] + D[r]);
		}
	}
	cout << dp[1][n];
	return 0;
}
