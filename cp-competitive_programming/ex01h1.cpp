#include <algorithm>
#include <iostream>
#include <vector>

const long long MxN = 2e9;

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	std::vector<long long> mem = {1ll, 3ll};
	for(int pos=3; mem.back() <= MxN; ++pos) {
		long long to_add = std::lower_bound(mem.begin(), mem.end(), pos) - mem.begin() + 1ll;
		mem.emplace_back(mem.back() + to_add);
	}
	int q;
	std::cin >> q;
	while(q--) {
		long long x;
		std::cin >> x;
		std::cout << std::lower_bound(mem.begin(), mem.end(), x) - mem.begin() + 1ll << "\n";
	}
	return 0;
}
