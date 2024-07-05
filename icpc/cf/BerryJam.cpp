#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

int a[MxN << 1], sum[MxN << 1];
map<int, int> cnt;

auto solve() -> void {
	int n;
	cin >> n;
	cnt[0] = 0;
	for(int i=1; i<=2*n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + (a[i] == 1 ? 1: -1);
	}
	for(int i=1; i<=n; ++i) {
		cnt[sum[i]] = i;
	}
	int answer = 1e9 + 100;
	for(int i=n; i<=2*n; ++i) {
		auto it = cnt.find(sum[i] - sum[2 * n]);
		if(it != cnt.end()) {
			answer = min(answer, i - it->second);
		}
	}
	cout << (answer >= 1e9 + 100 ? 2*n: answer) << "\n";
	cnt.clear();
	return ;
}

auto main(int argc, char *argv[]) -> int {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
