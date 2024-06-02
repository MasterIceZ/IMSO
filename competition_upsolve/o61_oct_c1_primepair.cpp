#include <bits/stdc++.h>

using namespace std;

const int MxN = 1000010;

int mem[MxN], dp[MxN];
bitset<MxN> is_prime;

inline void prime_sieve() {
	for(int i=2; i<MxN; ++i) {
		if(mem[i]) {
			continue;
		}
		is_prime[i] = true;
		for(int j=i*2; j<MxN; j+=i) {
			mem[j] = i;
		}
	}
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	
	prime_sieve();

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	dp[1] = 0;
	for(int i=2; i<MxN; ++i) {
		if(mem[i] == 0) {
			continue;
		}
		dp[i] = dp[i / mem[i]] + 1;
	}

	pair<int, int> res = make_pair(0, 0);
	int maxx = 0;
	for(int i=2; i<MxN; ++i) {
		int cur_x = b - (b % i);
		int cur_y = d - (d % i);
		if(cur_x < a || cur_y < c || dp[i] < maxx) {
			continue;
		}
		pair<int, int> cur = make_pair(cur_x, cur_y);
		if(dp[i] > maxx) {
			maxx = dp[i];
			res = cur;
		}
		else {
			res = max(cur, res);
		}
	}

	cout << res.first << " " << res.second << "\n";

	return 0;
}
