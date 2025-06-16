#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>

const int MxN = 200020;
const int MxT = 1010;
const long long MOD = 1e9 + 7ll;

struct thieve_t {
	std::pair<int, int> pos;
	int idx;
	thieve_t(int x, int y, int i):
		pos(x, y), idx(i) {}
	bool operator < (const thieve_t &o) const {
		return pos < o.pos;
	}
};

std::vector<thieve_t> thieves;
int x, y;
long long factorial[MxN], inverse_factorial[MxN], dp[MxT];

long long bin_pow(long long a, long long b) {
	long long res = 1ll;
	for(; b>0ll; b>>=1ll, a=(a*a)%MOD) {
		if(b & 1ll) {
			res = (res * a) % MOD;
		}
	}
	return res;
}

inline long long C(int n, int r) {
	if(n < r) {
		return 0ll;
	}
	return (((factorial[n] * inverse_factorial[r]) % MOD) * inverse_factorial[n - r]) % MOD;
}

inline long long get_ways(int x, int y) {
	long long cur_ways = C(x + y - 2, x - 1);
	std::pair<int, int> cur_pos = std::make_pair(x, y);
	for(auto [pos, idx]: thieves) {
		if(pos <= cur_pos) {
			long long to_del = (dp[idx] * C(x + y - (pos.first + pos.second), x - 1)) % MOD;
			cur_ways = (((cur_ways - to_del) % MOD) + MOD) % MOD;
		}
	}
	return cur_ways;
}

signed main(int argc, char *argv[]) {
	factorial[0] = 1ll;
	for(long long i=1ll; i<MxN; ++i) {
		factorial[i] = (factorial[i - 1] * i) % MOD;
	}
	inverse_factorial[MxN - 1] = bin_pow(factorial[MxN - 1], MOD - 2);
	for(long long i=MxN - 2; i>=0ll; --i) {
		inverse_factorial[i] = (inverse_factorial[i + 1] * (i + 1ll)) % MOD;
	}

	printf("%lld %lld", factorial[10], inverse_factorial[10]);
	
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i=1; i<=n; ++i) {
		scanf("%d %d", &x, &y);
		thieves.emplace_back(x, y, i);
	}
	std::sort(thieves.begin(), thieves.end());
	for(auto thieve: thieves) {
		dp[thieve.idx] = get_ways(thieve.pos.first, thieve.pos.second);
	}
	while(q--) {
		scanf("%d %d", &x, &y);
		printf("%lld\n", get_ways(x, y));
	}

	return 0;
}
