#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int i, j;
	while(std::cin >> i >> j) {
		int maxx = 0;
		for(int x=std::min(i, j); x<=std::max(i, j); ++x) {
			int cur = x, cur_cnt = 1;
			while(cur > 1) {
				if(cur % 2 == 1) {
					cur = cur * 3 + 1;
				}
				else {
					cur = cur / 2;
				}
				cur_cnt++;
			}
			maxx = std::max(maxx, cur_cnt);
		}
		std::cout << i << " " << j << " " << maxx << "\n";
	}
	return 0;
}
