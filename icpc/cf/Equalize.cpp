#include <bits/stdc++.h>

using namespace std;

inline void solve() {
	int n, answer = 0;
	cin >> n;
	vector<int> a(n);
	for(auto &x: a) {
		cin >> x;
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	for(int l=0, r=0; r<(int) a.size(); ++r) {
		while(l < (int) a.size() && a[r] - a[l] >= n) {
			l++;
		}
		answer = max(answer, r - l + 1);
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
