#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxA = 1000010;
const int MxN = 550;
const ll MOD = 1e9 + 7ll;

int n, k;
ll h[MxN], fac[MxA], inv[MxA], dp[MxN][MxN];

inline ll nCr(int n, int r) {
	return (((fac[n] * inv[r]) % MOD) * inv[n - r]) % MOD;
}

inline ll nPr(int n, int r) {
	if(n < r) {
		return 0ll;
	}
	return (fac[n] * inv[n - r]) % MOD;
}

int dfs(int l, int r, ll v) {
	if(l > r) {
		return 0;
	}
	int mid = l;
	for(int p=l; p<=r; ++p) {
		if(h[p] >= h[mid]) {
			continue;
		}
		mid = p;
	}
	int go_left = dfs(l, mid - 1, h[mid]);
	int go_right = dfs(mid + 1, r, h[mid]);
	vector<ll> cur_dp(MxN);
	for(int x=0; x<=min(r - l + 1, k); ++x) {
		for(int y=0; x+y<=min(r - l + 1, k); ++y) {
			ll to_add = (dp[go_left][x] * dp[go_right][y]) % MOD;
			cur_dp[x + y] = (cur_dp[x + y] + to_add) % MOD;
		}
	}
	for(int x=0; x<=min(r - l + 1, k); ++x) {
		for(int y=0; y<=x; ++y) {
			ll choosing = (nCr((r - l + 1) - (x - y), y) * nPr(h[mid] - v, y)) % MOD;
			ll to_add = (choosing * cur_dp[x - y]) % MOD;
			dp[mid][x] = (dp[mid][x] + to_add) % MOD;
		}
	}
	return mid;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	fac[0] = 1;
	for(ll i=1ll; i<(ll) MxA; ++i) {
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	auto mop = [&](ll a, ll b) {
		ll res = 1ll;
		for(; b>0ll; b>>=1ll, a=(a * a) % MOD) {
			if(b & 1ll) {
				res = (res * a) % MOD;
			}
		}
		return res;
	};
	inv[MxA - 1] = mop(fac[MxA - 1], MOD - 2ll);
	for(ll i=(ll) (MxA-2ll); i>=0ll; --i) {
		inv[i] = (inv[i + 1] * (i + 1ll)) % MOD;
	}

	cin >> n >> k;
	for(int i=1; i<=n; ++i) {
		cin >> h[i];
	}

	dp[0][0] = 1ll;
	int idx = dfs(1, n, 0);
	cout << dp[idx][k] << "\n";

	return 0;
}
