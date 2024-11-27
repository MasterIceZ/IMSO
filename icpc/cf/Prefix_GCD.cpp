#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

ll a[MxN];

void solve() {
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll answer = 0ll, cur_gcd = 0ll;
	for(int i=1; i<=n; ++i) {
		if(a[i] == cur_gcd) {
			answer += cur_gcd;
			continue;
		}
		cur_gcd = a[i];
		for(int j=i+1; j<=n; ++j) {
			a[j] = __gcd(a[i], a[j]);
		}
		sort(a + i + 1, a + n + 1);
		answer += cur_gcd;
	}
	cout << answer << "\n";
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
