#include <algorithm>
#include <iostream>
#include <string>

const int p10[] = {1, 10, 100, 1000};

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, answer = 0;
	std::cin >> n;
	for(int i=1; i<=n; ++i) {
		std::string s;
		std::cin >> s;
		int cur = 0;
		std::reverse(s.begin(), s.end());
		for(int j=0; j<4 && j<(int) s.size(); ++j) {
			cur += (s[j] - '0') * (p10[j]);
		}
		answer = (cur + answer) % 1250;
	}
	std::cout << (answer == 0 ? "yes" : "no") << "\n";
	return 0;
}
