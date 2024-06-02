#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 22;

string b, t;
ll v[1 << MxN], dp[1 << MxN];

inline int create_bit(string b) {
	int r = 0;
	for(auto x: b) {
		r <<= 1;
		r |= (x == '1');
	}
	return r;
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	int max_mask = (1 << n) - 1;
	for(int i=0; i<=max_mask; ++i) {
		cin >> b >> v[create_bit(b)];
	}

	dp[0] = v[0];
	for(int mask=1; mask<=max_mask; ++mask) {
		ll cur = -1e18;
		if(mask & 1) {
			cur = dp[mask ^ 1];
		}
		for(int bit=1; bit<n; ++bit) {
			int this_bit = (1 << bit);
			if(mask & this_bit) {
				cur = max(cur, dp[mask ^ this_bit]);
			}
			int before_bit = (1 << (bit - 1));
			if((mask & this_bit) && (mask & before_bit)) {
				cur = max(cur, dp[mask ^ this_bit ^ before_bit]);
			}
		}
		dp[mask] = v[mask] + cur;
	}
	
	while(q--) {
		cin >> t;
		cout << dp[create_bit(t)] << "\n";
	}

	return 0;
}
