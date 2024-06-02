#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;

int a[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, l, r;
	cin >> n >> l >> r;
	for(int i=1; i<=n; ++i) {
		a[i] = i;
	}
	reverse(a + l, a + r + 1);
	for(int i=1; i<=n; ++i) {
		cout << a[i] << " \n"[i == n];
	}
	return 0;
}
