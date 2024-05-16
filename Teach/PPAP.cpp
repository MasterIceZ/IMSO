#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> max_len;

bool PPAP(ll pos, int state) {
	if(state == 0) {
		return true;
	}
	if(pos <= max_len[state - 1]) {
		return PPAP(pos, state - 1);
	}
	if(pos == max_len[state - 1] + 1ll) {
		return true;
	}
	if(pos <= 2ll * max_len[state - 1] + 1ll) {
		return !PPAP(pos - max_len[state - 1] - 1ll, state - 1);
	}
	return PPAP(pos - 2ll * max_len[state - 1] - 1ll, state - 1);
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	max_len.emplace_back(1);
	while(max_len.back() <= (ll) 1e18) {
		max_len.emplace_back(max_len.back() * 3ll + 1ll);
	}
	int q;
	cin >> q;
	while(q--) {
		ll x;
		cin >> x;
		int len_idx = lower_bound(max_len.begin(), max_len.end(), x) - max_len.begin();
		cout << (PPAP(x, len_idx) ? "P": "A") << "\n";
	}
	return 0;
}
