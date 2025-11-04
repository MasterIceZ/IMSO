#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>

const int MxN = 8080;

long long a[MxN], c[MxN];

inline void solve() {
	int n;
	std::cin >> n;
	for(int i=1; i<=n; ++i) {
		std::cin >> a[i];
	}
	for(int i=1; i<=n; ++i) {
		std::cin >> c[i];
	}
	long long sum = std::accumulate(c + 1, c + n + 1, 0ll);
	std::set<std::pair<long long, long long>> st;
	for(int i=1; i<=n; ++i) {
		long long v = c[i];
		auto it = st.lower_bound(std::make_pair(a[i] + 1, 0));
		if(it != st.begin()) {
			v += std::prev(it)->second;
		}
		it = st.lower_bound(std::make_pair(a[i], 0));
		while(it!=st.end() && v >= it->second) {
			it = st.erase(it);
		}
		st.emplace(a[i], v);
	}
	std::cout << sum - st.rbegin()->second << "\n";
	return ;
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
