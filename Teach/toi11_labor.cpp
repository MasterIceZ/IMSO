#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1000010;

int n;
ll m, a[MxN];

bool ok(ll mid) {
	ll w = 0ll;
	for(int i=1; i<=n; ++i) {
		w += mid / a[i];
	}
	return w >= m;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	ll l = 0, r = 1e18 + 100ll;
	while(l < r) {
		ll mid = (l + r) / 2;
		if(ok(mid)) {
			r = mid;
		}
		else {
			l = mid + 1ll;
		}
	}
	cout << l << "\n";
	return 0;
}
