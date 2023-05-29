#include <iostream>

using namespace std;

using ll = long long;

const int MxN = 330;
const ll MOD = 1e9 + 7;
int n, k;
ll d, a[MxN], sum[MxN], dp[2][MxN][MxN];

inline void matrixChain(int state){
	for(int sz=1; sz<=n; ++sz){
		for(int l=1; l+sz-1<=n; ++l){
			int r = l + sz - 1;
			for(int m=l; m<r; ++m){
				ll left_sum = sum[m] - sum[l - 1];
				ll right_sum = sum[r] - sum[m];
				if(abs(left_sum - right_sum) <= d){
					ll mul = (dp[state & 1 ^ 1][l][m] * dp[state & 1 ^ 1][m + 1][r]) % MOD;
					dp[state & 1][l][r] = (dp[state & 1][l][r] + mul) % MOD;
				}
			}
		}
	}
	return ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> k >> d;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i=1; i<=n; ++i){
		for(int j=i; j<=n; ++j){
			dp[1][i][j] = 1ll;
		}
	}
	for(int state=2; state<=k; ++state){
		for(int i=1; i<=n; ++i){
			for(int j=i; j<=n; ++j){
				dp[state & 1][i][j] = 0ll;
			}
		}
		matrixChain(state);
	}
	cout << dp[k & 1][1][n];
	return 0;
}
