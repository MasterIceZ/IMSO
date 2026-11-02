#include <cmath>
#include <iostream>

const double EPS = 1e-7;

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	long long x, y;
	while(std::cin >> x >> y && (x != 0 || y != 0)) {
		if(x == y && x == 1) {
			std::cout << "0 1\n";
			continue;
		}
		int opt;
		for(int i=1; i<100; ++i) {
			opt = i;
			if(std::fabs(pow(x, 1.0 / i) - pow(y, 1.0 / i) - 1) < EPS) {
				break;
			}
		}
		long long n = (long long) round(pow(y, 1.0 / opt));
		if(n != 1) {
			std::cout << (y - 1) / (n - 1);
		}
		else {
			std::cout << opt;
		}
		std::cout << " " << x * (n + 1) - (y * n) << "\n";
	}
	return 0;
}
