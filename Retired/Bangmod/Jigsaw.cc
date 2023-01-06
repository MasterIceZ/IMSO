#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 1010;
const int MOD = 1e9 + 7;
ll dp[MxN][2];

int main(){
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int n;
    cin >> n;
	dp[0][0] = 1; dp[0][1] = 1;
	dp[1][0] = 0; dp[1][1] = 1;
	dp[2][0] = 1;
	for(int i=2; i<=n; ++i){
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];	
	}
	for(int i=3; i<=n; ++i){
		dp[i][0] = dp[i - 2][0] + dp[i - 3][0] + 2 * dp[i - 2][1];
	}
	cout << dp[n][0];
    return 0;
}
