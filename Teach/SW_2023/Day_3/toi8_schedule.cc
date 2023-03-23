#include <bits/stdc++.h>
using namespace std;

const int MxN = 1010;
int n, m;
int a[MxN], b[MxN];
pair<int, int> dp[MxN][MxN];

pair<int, int> operator + (const pair<int, int> a, const int b){
	if(a.second + b > m){
		return make_pair(a.first + 1, b);
	}
	return make_pair(a.first, a.second + b);
}

int main(){
	scanf("%d %d", &m, &n);
	for(int i=1; i<=n; ++i){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=n; ++i){
		scanf("%d", &b[i]);
	}
	dp[0][0] = make_pair(1, 0);
	for(int i=1; i<=n; ++i){
		dp[i][0] = dp[i - 1][0] + a[i];
		dp[0][i] = dp[0][i - 1] + b[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			dp[i][j] = min(dp[i - 1][j] + a[i], dp[i][j - 1] + b[j]);
		}
	}
	printf("%d\n%d\n", dp[n][n].first, dp[n][n].second);
	return 0;
}
