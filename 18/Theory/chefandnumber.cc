#include <bits/stdc++.h>
using namespace std;

const int MxN = 1000010;
int a[MxN], dp[MxN];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, sz = 0;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	reverse(a + 1, a + n + 1);
	for(int i=1; i<=n; ++i){
		int idx = lower_bound(dp, dp + sz, a[i]) - dp;
		dp[idx] = a[i];
		if(idx == sz){
			sz++;
		}
	}
	cout << sz;
	return 0;
}
