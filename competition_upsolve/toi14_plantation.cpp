#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline ll closest_pair(vector<pair<ll, ll>> pts) {
	sort(pts.begin(), pts.end());
	set<pair<ll, ll>> st;

	ll res = 1e18 + 100ll;
	int it = 0;
	for(auto pt: pts) {
		ll cur_min = ceil(sqrt((double) res));
		while(pt.first - pts[it].first >= cur_min) {
			st.erase(make_pair(pts[it].second, pts[it].first));
			++it;
		}
		auto left_pos = st.lower_bound(make_pair(pt.first - cur_min, pt.second));
		auto right_pos = st.upper_bound(make_pair(pt.first + cur_min, pt.second));
		for(; left_pos != right_pos; ++left_pos) {
			ll x = pt.first - left_pos->second;
			ll y = pt.second - left_pos->first;
			res = min(res, x * x + y * y);
		}
		st.emplace(pt.second, pt.first);
	}
	return res;
}

inline void solve() {
	int n;
	ll r, d;
	cin >> n >> r >> d;
	vector<pair<ll, ll>> pts;
	for(auto &x: pts) {
		cin >> x.first >> x.second;
	}
	// cout << (closest_pair(pts) - 2ll * r >= d ? "Y": "N");
	cout << closest_pair(pts);
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << "\n";
	}
	return 0;
}
