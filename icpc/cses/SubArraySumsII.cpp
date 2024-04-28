#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<ll, ll> c;
ll k, pref_sum = 0ll, x, answer = 0ll;

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n >> k;
	c[0] = 1ll;
	for(int i=1; i<=n; ++i) {
		cin >> x;
		pref_sum += x;
		answer += c[pref_sum - k];
		c[pref_sum]++;
	}
	cout << answer << "\n";
	return 0;
}
