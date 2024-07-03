#include <bits/stdc++.h>

using namespace std;

const int MxN = 550;

int req[MxN];

inline void solve() {
	int n, k;
	cin >> n >> k;
	cout << (req[k] > n ? "NO": "YES") << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	req[1] = 1;
	for(int i=2; i<=500; ++i) {
		req[i] = req[i - 1] + 1 + i;
	}

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
