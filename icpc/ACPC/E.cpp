#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll x;

inline void solve() {
	int n;
	cin >> n;
	vector<int> cnt(64);
	for(int i=1; i<=n; ++i) {
		cin >> x;
		if(x != 0) {
			cnt[__lg(x)]++;
		}
	}
	cout << max(1, *max_element(cnt.begin(), cnt.end())) << "\n";
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
