#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18 + 100ll;
const int MxN = 55;
const int MxH = 55050;

ll c[MxN], dp[MxH];
int h[MxN];

inline void solve() {
	int n, x;
	cin >> n >> x;
	for(int i=1; i<=n; ++i) {
		cin >> c[i] >> h[i];
	}
	int sum_h = accumulate(h + 1, h + n + 1, 0);
	for(int i=1; i<=sum_h; ++i) {
		dp[i] = -INF;
	}
	dp[0] = 0;
	for(int i=1; i<=n; ++i) {
		for(int cur_h=sum_h; cur_h>=h[i]; --cur_h) {
			if(dp[cur_h - h[i]] < c[i]) {
				continue;
			}
			dp[cur_h] = max(dp[cur_h], dp[cur_h - h[i]] - c[i]);
		}
		for(int cur_h=0; cur_h<=sum_h; ++cur_h) {
			if(dp[cur_h] <= -INF) {
				continue;
			}
			dp[cur_h] += x;
		}
	}
	int answer = 0;
	for(int cur_h=sum_h; cur_h>=0; --cur_h) {
		if(dp[cur_h] <= -INF) {
			continue;
		}
		answer = cur_h;
		break;
	}
	cout << answer << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
