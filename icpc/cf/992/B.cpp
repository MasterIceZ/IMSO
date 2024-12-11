#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 110;
const int INF = 1e9 + 100;

int a[MxN], cnt[MxN], idx[MxN];

inline void solve() {
	int n;
	cin >> n;
	if(n <= 2) {
		cout << n << "\n";
		return ;
	}
	int cnt = 2, cur = 4;
	while(cur < n) {
		cnt++;
		cur = 2 + cur * 2;
	}
	cout << cnt << "\n";
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
