#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

ll a[MxN], pref_sum[MxN];

inline void solve() {
	ll n;
	cin >> n;
	for(int i=1; i<=(int) n; ++i) {
		cin >> a[i];
		pref_sum[i] = a[i] + pref_sum[i - 1];
	}
	ll answer = 0ll;
	for(ll i=1ll; i<=n; ++i) {
		for(ll ps=0ll; ps+i<=n; ) {
			ll pw = i * i;
			ll to_add = a[ps + i] - a[ps - 1];
			if(to_add == pw) {
				answer += 1ll;
			}
			ps += (abs(to_add - pw) / n) + 1ll;
		}
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
