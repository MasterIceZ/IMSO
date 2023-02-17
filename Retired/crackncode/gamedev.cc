#include <iostream>

using namespace std;

using ll = long long;

const int MxN = 200020;
ll dp[MxN];

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> dp[i];
		dp[i] = dp[i - 1] + dp[i];
	}
	ll answer = 0ll;
	for(int i=1; i<=n; ++i){
		for(int j=i+1; j<=n; ++j){
			answer = max(answer, (j - i) * (dp[j] - dp[j - 1]) - (dp[j - 1] - dp[i - 1]));
		}
	}
	cout << answer;
	return 0;
}
