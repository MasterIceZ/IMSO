#include <bits/stdc++.h>
using namespace std;

const int MxN = 1010;
char a[MxN];
int dp[MxN][MxN];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		scanf(" %c", &a[i]);
	}
	for(int sz=2; sz<=n; ++sz){
		for(int l=1; l+sz-1<=n; ++l){
			int r = l + sz - 1;
			if(a[l] == a[r]){
				dp[l][r] = dp[l + 1][r - 1] + 1;
			}
			else{
				for(int k=l; k<r; ++k){
					dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
				}
			}
		}
	}
	printf("%d\n", dp[1][n]);
	return 0;
}
