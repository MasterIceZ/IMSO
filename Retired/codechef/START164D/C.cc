#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
	int n;
	cin >> n;
	if(n % 2 == 0) {
		cout << "-1";
	}
	else {
		for(int i=1; i<=n; ++i) {
			cout << (i & 1 ? i: n - i + 1) << " ";
		}
	}
	cout << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
