#include <bits/stdc++.h>

using namespace std;

inline void solve() {
	int a, b;
	cin >> a >> b;
	cout << (b > a ? "YES": "NO") << "\n";	
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
