#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 550;

pair<ll, ll> p[MxN];
ll dp[MxN][MxN];

inline ll calc_distance(pair<ll, ll> a, pair<ll, ll> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}	

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	int n, q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> p[i].first >> p[i].second;
	}

	memset(dp, 0x3f, sizeof dp);
	for(int i=1; i<=n; ++i) {
		dp[i][1] = calc_distance(p[1], p[i]);
	}
	for(int food=2; food<=n; ++food) {
		for(int from=1; from<=n; ++from) {
			for(int to=1; to<=n; ++to) {
				ll distance = calc_distance(p[from], p[to]);
				dp[to][food] = min(dp[to][food], max(dp[from][food - 1], distance));
			}
		}
	}

	ll answer = 0ll;
	while(q--) {
		ll s;
		cin >> s;

		auto ok = [&](int x) {
			return s < dp[n][x];
		};

		int l = 1, r = n;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(ok(mid)) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
		answer += (ll) l;
	}
	cout << answer << "\n";
	
	return 0;
}
