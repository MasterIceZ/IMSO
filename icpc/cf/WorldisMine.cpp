#include <bits/stdc++.h>

using namespace std;

auto solve() -> void {
	int n;
	cin >> n;
	vector<int> a(n + 1), v;
	map<int, int> cnt;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for(auto &[key, val]: cnt) {
		v.emplace_back(val);
	}
	int dp_sz = (int) v.size();
	vector<int> dp(dp_sz, (int) 1e9 + 100);
	dp[0] = 0;
	for(int i=1; i<=dp_sz; ++i) {
		vector<int> new_dp = dp;
		for(int j=1; j<=dp_sz; ++j) {
			if(dp[j - 1] + v[i - 1] > i - j) {
				continue;
			}
			new_dp[j] = min(new_dp[j], dp[j - 1] + v[i - 1]);
		}
		dp = new_dp;
	}
#ifdef ICY
	cerr << "D: ";
	for(int i=1; i<=dp_sz; ++i) {
		cerr << dp[i] << " \n"[i == dp_sz];
	}
#endif
	int answer = dp_sz;
	while(dp[answer] >= 1e9 + 100) {
		answer--;
	}
	cout << dp_sz - answer << "\n";
	return ;
}

auto main(int argc, char *argv[]) -> signed {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
