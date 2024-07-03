#include <bits/stdc++.h>

using namespace std;

inline void solve() {
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cout << "31"[i == n] << " \n"[i == n];
	}
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
