#include <cmath>
#include <iostream>
#include <iomanip>

const long double G = 6.674 * 1e-11;

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	long double ms, mp, d;
	std::cin >> ms >> mp >> d;
	std::cout << std::fixed << std::setprecision(0) << std::round(std::sqrt(G * ms / (d * d * d))) << "\n";
	return 0;
}
