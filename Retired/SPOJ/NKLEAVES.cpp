#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int n;
ll a[MxN], suf_sum[MxN];

inline ll cost(int l, int r) {
	ll to_remove = 0ll;
	if(r < n) {
		to_remove = suf_sum[r] * (1ll << (r - l));
	}
	return suf_sum[l] - to_remove;
}

void DP(int l, int r, int opt_l, int opt_r, vector<ll>& new_dp, vector<ll>& dp) {
	if(l > r) {
		return ;
	}
	int mid = (l + r) >> 1;
	pair<ll, int> best = make_pair(1e18 + 100ll, -1);
	for(int k=opt_l; k<=min(mid, opt_r); ++k) {
		best = min(best, make_pair(dp[k] + cost(k + 1, mid), k));
	}
	new_dp[mid] = best.first;
	DP(l, mid - 1, opt_l, best.second, new_dp, dp);
	DP(mid + 1, r, best.second, opt_r, new_dp, dp);
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int i=n-2; i>=0; --i) {
		suf_sum[i] = suf_sum[i + 1] * 2ll + a[i + 1];
	}
	vector<ll> dp(n + 1, 0ll);
	for(int i=1; i<=n; ++i) {
		dp[i] = cost(1, i);
	}
	for(int state=2; state<=k; ++state) {
		vector<ll> new_dp(n + 1, 0ll);
		DP(state, n, 1, n, new_dp, dp);
		dp = new_dp;
	}
	cout << dp[n];
	return 0;
}
