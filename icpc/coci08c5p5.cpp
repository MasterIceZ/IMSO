#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll power[16], dp[16][11], l, r;

ll get_intersection(ll state, ll sum) {
	if(state < 0ll) {
		return 0ll;
	}
	ll lb = max(sum * power[state], l);
	ll rb = min((sum + 1ll) * power[state] - 1ll, r);
	return lb <= rb ? rb - lb + 1ll: 0ll;
}

ll DP(ll state, ll current_digit, ll current_sum) {
	ll state_min = current_sum * power[state];
	ll state_max = (current_sum + 1ll) * power[state] - 1ll;
	if(state_min > r || state_max < l) {
		return 0ll;
	}
	if(dp[state][current_digit] != -1ll) {
		return dp[state][current_digit];
	}
	dp[state][current_digit] = 0ll;
	for(ll next_digit=0ll; next_digit<=9ll; ++next_digit) {
		if(next_digit == current_digit) {
			continue;
		}
		ll next_sum = current_sum;
		for(ll remove_state=1ll; remove_state<=state; ++remove_state) {
			next_sum = next_sum * 10ll + next_digit;
			ll mul = next_digit * remove_state * remove_state;
			ll intersection = get_intersection(state - remove_state, next_sum) - get_intersection(state - remove_state - 1, next_sum * 10ll + next_digit);
			dp[state][current_digit] += mul * intersection + DP(state - remove_state, next_digit, next_sum);
		}
	}
	return dp[state][current_digit];
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	power[0] = 1ll;
	for(int i=1; i<=15; ++i) {
		power[i] = power[i - 1] * 10ll;
	}
	cin >> l >> r;
	memset(dp, -1ll, sizeof dp);
	cout << DP(15ll, 10ll, 0ll) << "\n";
	return 0;
}
