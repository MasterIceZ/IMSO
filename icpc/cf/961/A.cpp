#include <bits/stdc++.h>

using namespace std;

inline void solve() {
	int n, k, cnt = 0;
	cin >> n >> k;
	int v = n;
	while(k > 0) {
		k -= v;
		if(++cnt % 2 == 1) {
			--v;
		}
	}
	cout << cnt << "\n";
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
