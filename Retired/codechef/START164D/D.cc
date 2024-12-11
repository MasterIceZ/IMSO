#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

ll a[MxN], l, r;

inline void solve() {
	int n;
	cin >> n >> l >> r;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	bool found_same = false;
	for(int i=2; i<=n; ++i) {
		if(a[i] == a[i - 1]) {
			found_same = true;
		}
	}
	if(found_same && l == 0) {
		cout << "YES";
		return ;
	}
	if(n >= 9) {
		cout << "NO";
		return ;
	}
	ll tot = 1ll;
	for(int i=1; i<=n; ++i) {
		for(int j=i+1; j<=n; ++j) {
			ll t = a[i] ^ a[j];
			if(t * tot > r) {
				cout << "NO";
				return ;
			}
			tot *= t;
		}
	}
	if(l <= tot && tot <= r) {
		cout << "YES";
	}
	else {
		cout << "NO";
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
