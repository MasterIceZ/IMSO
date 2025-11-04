#include <iostream>

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while(t--) {
		long long n;
		std::cin >> n;
		if(n == 0) {
			std::cout << "0\n";
			continue;
		}
		n = n < 0ll ? -n : n;
		long long res = 0ll, sum = 0ll;
		while(true) {
			res += 1ll;
			sum += res;
			if(sum >= n && (sum - n) % 2ll == 0ll) {
				break;
			}
		}
		std::cout << res << "\n";
	}
	return 0;
}
