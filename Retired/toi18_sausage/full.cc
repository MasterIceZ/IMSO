#include <bits/stdc++.h>
using namespace std;
const int MxN = 5050;
int a[MxN], dp[MxN][MxN], answer[MxN];
int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		dp[i][i] = a[i];
	}
	for(int sz=2; sz<=n; ++sz){
		for(int l=1; l+sz-1<=n; ++l){
			int r = l + sz - 1;
			dp[l][r] = abs(a[l] - a[r]) + max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r]);
		}
	}
	for(int i=1; i<=n; ++i){
		answer[i] = dp[1][i];
		for(int j=1; j<i; ++j){
			answer[i] = max(answer[i], answer[j] + dp[j + 1][i]);
		}
	}
	cout << answer[n];
	return 0;
}
