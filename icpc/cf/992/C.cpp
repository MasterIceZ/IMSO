#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
	int n;
	ll k;
	cin >> n >> k;
	k -= 1;
	deque<int> v = {n};
	for(int i=n-1; i>=1; --i) {
		if(k & 1) {
			v.emplace_front(i);
		}
		else {
			v.emplace_back(i);
		}
		k /= 2;
	}
	if(k >= 1) {
		cout << "-1\n";
		return ;
	}
	reverse(v.begin(), v.end());
	for(auto x: v) {
		cout << x << " ";
	}
	cout << "\n";
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
