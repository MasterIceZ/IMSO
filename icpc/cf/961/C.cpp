#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;
using ll = long long;

ll a[MxN];

inline void solve() {
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}
	ll max_a = *max_element(a + 1, a + n + 1);
	ll answer = 0ll, pre = 0, cur = 0;
	for(int i=2; i<=n; ++i) {
		if(pre == 0 && a[i - 1] <= a[i]) {
			continue;
		}
		if(a[i] == 1) {
			cout << "-1\n";
			return ;
		}
		while(a[i - 1] > a[i] && a[i] * a[i] <= max_a) {
			answer += 1;
			a[i] = a[i] * a[i];
		}
		cur = pre + (a[i - 1] > a[i]);
		answer = answer + cur;
		pre = cur;
	}
	cout << answer << "\n";
	return ;
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
