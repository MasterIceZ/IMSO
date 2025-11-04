#include <iostream>

const int MxN = 44;

long long fibo[MxN];

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

	fibo[1] = fibo[2] = 0ll;
	for(int i=3; i<MxN; ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	int t;
	std::cin >> t;
	while(t--) {
		long long n, x;
		std::cin >> n >> x;
		while(n > 2) {
			if(x <= fibo[n - 2]) {
				n -= 2;
			}
			else {
				n -= 1;
				x -= fibo[n - 2];
			}
		}
		std::cout << (n == 1 ? "I" : "U") << "\n";
	}
	return 0;
}
