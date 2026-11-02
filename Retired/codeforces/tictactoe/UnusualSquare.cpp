#include <iostream>

int main() {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, sum = 0;
	std::cin >> n;
	for(int i=1, x; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			std::cin >> x;
			if(i == j) {
				sum = (sum + x) % 2;
			}
		}
	}
	int q;
	std::cin >> q;
	while(q--) {
		int o, x;
		std::cin >> o;
		if(o == 1) {
			std::cin >> x;
			sum = !sum;
		}
		else if(o == 2) {
			std::cin >> x;
			sum = !sum;
		}
		else {
			std::cout << sum;
		}
	}
	return 0;
}
