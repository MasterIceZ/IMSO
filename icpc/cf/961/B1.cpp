#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

ll m, a[MxN];

inline void solve() {
	int n;
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
	}	
	sort(a + 1, a + n + 1);
	ll cur_sum = 0, answer = 0;
	for(int l=1, r=1; r<=n; ++r) {
		cur_sum += a[r];
		while(cur_sum > m || a[r] - a[l] > 1) {
			cur_sum -= a[l];
			l++;
		}
		answer = max(answer, cur_sum);
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
