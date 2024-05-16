#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll dp[100010], dp2[100010];
int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<ll> v(n+1);
	for(int i=1; i<=n; ++i){
		cin >> v[i];
		v[i] -= m/2;
		dp[i] += dp[i-1] + v[i];
		cerr << "DP: " << dp[i] << "\n";
	}
	vector<ll> lis;
	for(int i=1; i<=n; ++i){
		if(dp[i] <= 0){
			continue;
		}
		if(i < n && dp[i] >= dp[n]){
			continue;
		}
		cerr << "X: " << i << "\n";
		int idx = lower_bound(lis.begin(), lis.end(), dp[i]) - lis.begin();
		if(idx == lis.size()){
			lis.push_back(dp[i]);
		}
		else{
			lis[idx] = dp[i];
		}
	}
	for(auto x: lis) {
		cerr << "D: " << x << "\n";
	}
	cout << lis.size() << endl;
	return 0;
}
