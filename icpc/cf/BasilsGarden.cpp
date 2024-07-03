#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

int a[MxN];

inline void solve() {
	int n, answer = 0;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	for(int i=n; i>=1; --i) {
		answer = max(answer + 1, a[i]);
	}
	cout << answer;
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	int q;
	cin >> q;
	while(q--) {
		solve();
		cout << "\n";
	}

	return 0;
}
