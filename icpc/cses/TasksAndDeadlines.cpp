#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;
pair<ll, ll> a[MxN];

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + n + 1);
	ll total_time = 0, res = 0;
	for(int i=1; i<=n; ++i) {
		total_time += a[i].first;
		res += a[i].second - total_time;
	}
	cout << res << "\n";
	return 0;
}
