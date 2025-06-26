#include <iostream>
#include <map>
#include <utility>

const int MxN = 200020;
const long long INF = 1e18 + 100ll;

long long m, a[MxN];
std::map<long long, long long> cnt;

inline long long squared(long long x) {
	return x * x;
}

inline long long calc(long long a, long long b) {
	return squared(a / b + 1ll) * (a % b) + squared(a / b) * (b - (a % b));
}

inline std::pair<long long, long long> calc_alien(long long mid) {
	std::pair<long long, long long> res = std::make_pair(0ll, 0ll);
	for(auto it: cnt) {
		long long l = 1, r = it.first;
		while(l < r) {
			long long md = (l + r) >> 1;
			if(calc(it.first, md) - calc(it.first, md + 1) >= mid) {
				l = md + 1;
			}
			else {
				r = md;
			}
		}
		res.first += calc(it.first, l) * it.second;
		res.second += (l - 1ll) * it.second;
	}
	return res;
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for(int i=1; i<=n; ++i) {
		std::cin >> a[i];
		cnt[a[i] - a[i - 1]] += 1;
	}
	std::cin >> m;

	long long l = 1, r = INF;
	while(l < r) {
		long long mid = (l + r + 1ll) >> 1ll;
		if(calc_alien(mid).first <= m) {
			l = mid;
		}
		else {
			r = mid - 1ll;
		}
	}
	std::pair<long long, long long> best = calc_alien(l + 1);
	std::cout << best.second + (best.first - m + l - 1ll) / l << "\n";
	return 0;
}
