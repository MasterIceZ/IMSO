#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

const long long INF = 1e18 + 100ll;

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	
	std::vector<long long> v;
	v.emplace_back(0ll);
	for(long long i=1ll; ; i+=2) {
		if(v.back() > INF) {
			break;
		}
		v.emplace_back(i * i + v.back());
	}

	std::vector<long long> p = {1, 5, 20, 100};

	int t;
	std::cin >> t;
	while(t--) {
		std::vector<long long> b(4);
		for(auto &x: b) {
			std::cin >> x;
		}
		long long sum = std::accumulate(b.begin(), b.end(), 0ll);
		auto it = upper_bound(v.begin(), v.end(), sum);
		--it;
		long long remains = sum - *it, total = 0ll;
		for(int s=3; s>=0 && remains > 0; --s) {
			long long u = std::min(b[s], remains);
			remains -= u;
			total += u * p[s];

		}
		std::cout << (it - v.begin()) << " " << total << "\n";
	}
	return 0;
}
