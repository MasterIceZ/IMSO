#include <bits/stdc++.h>

using namespace std;

inline void solve() {
	int x, y;
	cin >> x >> y;
	int have = x * 10, k = 0;
	while(have + k * 100 < (10 + k) * y) {
		k++;
	}
	cout << k << "\n";
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
