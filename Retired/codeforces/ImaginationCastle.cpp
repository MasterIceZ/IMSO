#include <cstring>
#include <iostream>
#include <vector>

const int MxN = 200020;

int r[MxN], c[MxN];

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, m, k, x, y;
	std::cin >> n >> m >> k;
	while(k--) {
		std::cin >> x >> y;
		r[x] = std::max(r[x], y);
		c[y] = std::max(c[y], x);
	}
	bool ok = false;
	int cur_i = n, cur_j = m;
	while(cur_i > 0 && cur_j > 0) {
		if(r[cur_i] >= cur_j) {
			--cur_i;
			continue;
		}
		if(c[cur_j] >= cur_i) {
			--cur_j;
			continue;
		}
		if(cur_i == 1 && cur_j == 1) {
			ok = true;
			break;
		}
		--cur_i, --cur_j;
	}
	std::cout << (ok ? "Bhinneka": "Chaneka") << "\n";
	return 0;
}
