#include <algorithm>
#include <iostream>
#include <vector>

long long u, w, answer = 0ll;

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, m, k;
	std::cin >> n >> m >> u >> k;
	std::vector<long long> weights;
	for(int i=1, u, v; i<=m; ++i) {
		std::cin >> u >> v >> w;
		weights.emplace_back(w);
	}
	std::sort(weights.begin(), weights.end());
	long long answer = 0ll;
	for(int i=0, c=n; i<m && c>k; ++i, --c) {
		answer += weights[i];
	}
	std::cout << answer * u << "\n";
	return 0;
}
