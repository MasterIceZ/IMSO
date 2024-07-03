#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
	ll a;
	cin >> a;
	if(a == 2ll) {
		cout << 4 << " " << 8 << "\n";
	}
	else {
		cout << a * 2ll << " " << a * a << "\n";
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
