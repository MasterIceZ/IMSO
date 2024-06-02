#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for(auto &x: a) {
		cin >> x;
	}
	ll answer = 0ll;
	for(int i=0, j=0; i<n; i=j, j=i) {
		ll cur_max = a[i];
		while(j < n && a[i] * a[j] > 0) {
			cur_max = max(cur_max, a[j++]);
		}
		answer += cur_max;
	}
	cout << answer;
	return ;
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
