#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;

int a[MxN][MxN], nim[MxN << 1];

inline void solve() {
	int r, c;
	cin >> r >> c;
	for(int i=2; i<=r+c; ++i) {
		nim[i] = 0;
	}
	for(int i=1; i<=r; ++i) {
		for(int j=1; j<=c; ++j) {
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=r; ++i) {
		for(int j=1; j<=c; ++j) {
			nim[i + j] ^= a[i][j];
		}
	}
	cout << (*max_element(nim + 2, nim + (r + c) + 1) > 0 ? "Ashish": "Jeel") << "\n";
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
