#include <iostream>

struct parabola_t {
	long long a, b, c;
	int idx;
	
	bool operator < (const parabola_t& o) {
	}
};

inline void solve() {
	int n;
	std::cin >> n;
}

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}
