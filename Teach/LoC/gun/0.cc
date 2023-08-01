#include <bits/stdc++.h>
using namespace std;

struct vertex_t {
	int minn, maxx, dp_min, dp_max;
	vertex_t(int _minn=1e9+100, int _maxx=-1e9-100, int _dp_min=1e9+100, int _dp_max=-1e9-100):
		minn(_minn), maxx(_maxx), dp_min(_dp_min), dp_max(_dp_max) {}
};

const int MxN = 200020;

vertex_t dp[MxN]; // dp[i] -> from 1 to i

inline void solve() {
	int n, cnt = 0, u, v, x, k;
	char opr;
	cin >> n;
	dp[++cnt] = {0, 1, 0, 1};
	for(int i=1; i<=n; ++i) {
		cin >> opr;
		if(opr == '+') {
			cin >> v >> x;
			// add x to vertex `v`
			int minn = min(dp[v].minn + x, 0);
			int maxx = max(dp[v].maxx + x, 0);
			dp[++cnt] = {
				minn,
				maxx,
				min(dp[v].dp_min, minn),
				max(dp[v].dp_max, maxx)
			};
		}
		else {
			cin >> u >> v >> k;
			// sub-segment from 1 to v can be k ? YES: NO
			cout << ((dp[v].dp_min <= k && k <= dp[v].dp_max) ? "yes": "no") << "\n";
		}
	}
	return ;
}

int main() {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
		//cout << "\n";	
	}
	return 0;
}
