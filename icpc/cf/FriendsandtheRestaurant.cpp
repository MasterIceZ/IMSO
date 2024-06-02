#include <bits/stdc++.h>

using namespace std;

inline void solve() {
	int n, cnt = 0;
	cin >> n;
	vector<int> x(n), y(n);
	for(auto &e: x) {
		cin >> e;
	}
	for(auto &e: y) {
		cin >> e;
	}
	vector<pair<int, int>> z(n);
	for(int i=0; i<n; ++i) {
		z[i] = make_pair(y[i] - x[i], i);
	}
	sort(z.begin(), z.end(), greater<pair<int, int>> ());
	for(int l=0, r = n - 1; l<n && l<r; ++l, --r) {
		while(l < r && z[l].first + z[r].first < 0) {
			r--;
		}
		if(l >= r) {
			break;
		}
		cnt++;
	}	
	cout << cnt << "\n";
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
