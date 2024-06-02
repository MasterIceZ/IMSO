#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;

int a[MxN], x[MxN][MxN], sum[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i) {
		cin >> a[i];
	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cin >> x[i][j];
			sum[j] += x[i][j];
		}
	}
	bool no = false;
	for(int i=1; i<=m; ++i) {
		no |= (sum[i] < a[i]);
	}
	cout << (no ? "No": "Yes") << "\n";
	return 0;
}
