#include <cmath>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	double n, p;
	while(std::cin >> n >> p) {
		std::cout << std::fixed << std::setprecision(0) << pow(p, 1 / n) << "\n";
	}
	return 0;
}
