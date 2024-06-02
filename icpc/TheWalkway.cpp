#include <bits/stdc++.h>

using namespace std;

const int MxN = 1000010;

int a[MxN];

inline int ceil_divide(int a, int b) {
	return (a - 1) / b + 1;
}

inline void solve() {
	int n, m, d;
	cin >> n >> m >> d;
	a[0] = 1 - d;
	for(int i=1; i<=m; ++i) {
		cin >> a[i];
	}
	a[m + 1] = n + 1;
	
	int answer = 0;
	for(int i=1; i<=m; ++i) {
		answer += ceil_divide(a[i] - a[i - 1], d);
	}
	answer += ceil_divide(a[m + 1] - a[m], d);

	int cnt = 0;
	for(int i=2; i<=m+1; ++i) {
		cnt += (ceil_divide(a[i] - a[i - 2], d) < ceil_divide(a[i] - a[i - 1], d) + ceil_divide(a[i - 1] - a[i - 2], d));
	}

	cout << answer - 1 - (cnt != 0) << " " << (cnt != 0 ? cnt: m);
	return ;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << "\n";
	}
	return 0;
}
