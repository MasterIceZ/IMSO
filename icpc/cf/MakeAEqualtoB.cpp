#include <bits/stdc++.h>

using namespace std;

inline void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto &x: a) {
		cin >> x;
	}
	for(auto &x: b) {
		cin >> x;
	}
	int res = accumulate(a.begin(), a.end(), 0) - accumulate(b.begin(), b.end(), 0);
	int sum_xor = 0;
	for(int i=0; i<=n-1; ++i) {
		sum_xor += (a[i] ^ b[i]);
	}
	cout << min(abs(res) + 1, sum_xor) << "\n";
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
