#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const int INF = 1e9 + 100;
const char CHRS[] = {'B', 'G', 'C'};

int a[9];

inline std::string get_answer(std::vector<int> v) {
	std::string r = "";
	for(auto x: v) {
		r += CHRS[x];
	}
	return r;
}

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	while(std::cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8]) {
		int sum = a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8];
		std::vector<int> perm = {0, 1, 2};
		int minn = INF;
		std::string answer = "";
		do {
			int cur = sum - a[perm[0]] - a[perm[1] + 3] - a[perm[2] + 6];
			if(cur == minn) {
				answer = std::min(answer, get_answer(perm));
			}
			else if(cur < minn) {
				minn = cur;
				answer = get_answer(perm);
			}
		} while(next_permutation(perm.begin(), perm.end()));

		std::cout << answer << " " << minn << "\n";
	}
}
