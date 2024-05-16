#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

ll t, p, v, a[MxN], lis[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n >> t;
	for(int i=1; i<=n; ++i) {
		cin >> p >> v;
		a[i] = p + v * t;
	}
	int sz = 0;
	for(int i=1; i<=n; ++i) {
		int idx = upper_bound(lis, lis + sz, -a[i]) - lis;
		lis[idx] = -a[i];
		sz += (sz == idx);
	}
	cout << sz << "\n";
}
