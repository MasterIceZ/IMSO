#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxC = 18;

int cnt[MxC], dp[1 << MxC];
string s;

inline void solve() {
	int n, c, k;
	cin >> n >> c >> k >> s;
	int max_mask = (1 << c) - 1;
	for(int i=0; i<c; ++i) {
		cnt[i] = 0;
	}
	for(int i=0; i<=max_mask; ++i) {
		dp[i] = false;
	}
	for(int i=0; i<k-1; ++i) {
		cnt[s[i] - 'A']++;
	}
	for(int i=k-1; i<n; ++i) {
		cnt[s[i] - 'A']++;
		int no_mask = 0;
		for(int bit=0; bit<c; ++bit) {
			if(cnt[bit] != 0) {
				continue;
			}
			int this_mask = (1 << bit);
			no_mask |= this_mask;
		}
		dp[no_mask] = true;
		cnt[s[i - k + 1] - 'A']--;
	}
	int last_mask = (1 << (s[n - 1] - 'A'));
	dp[max_mask ^ last_mask] = true;
	for(int bit=0; bit<c; ++bit) {
		int this_bit = (1 << bit);
		for(int mask=0; mask<=max_mask; ++mask) {
			if(!(mask & this_bit)) {
				continue;
			}
			int remove_this = (mask ^ this_bit);
			dp[remove_this] |= dp[mask];
		}
	}
	int answer = c;
	for(int i=0; i<=max_mask; ++i) {
		if(dp[i]) {
			continue;
		}
		answer = min(answer, __builtin_popcount(i));
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
