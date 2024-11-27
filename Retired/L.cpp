#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

unordered_map<ll, ll> mp;
ll a[MxN];

inline void solve() {
	int n;
	cin >> n;
	ll pref_sum = 0ll, cnt = 0ll;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	mp.clear();
	for(int i=1; i<=n; ++i) {
		pref_sum += a[i];
		for(ll j=1ll; j*j<=pref_sum; ++j) {
			ll tar = j * j;
			ll prev = pref_sum - tar;
			if(mp[prev] != 0) {
				cnt += mp[prev];
			}
		}
		mp[pref_sum]++;
	}
	cout << cnt << "\n";
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
