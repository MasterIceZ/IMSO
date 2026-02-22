#pragma GCC optimize("Ofast")

#include <algorithm>
#include <iostream>
#include <set>
#include <string>

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int k;
	std::cin >> k;
	std::string s = "";
	for(int i=0, x; i<4; ++i) {
		std::cin >> x;
		char c = 'a' + i;
		while(x--) {
			s += c;
		}
	}
	std::set<std::string> answer;
	do {
		answer.emplace(std::string(s.begin(), s.begin() + k));
	} while(std::next_permutation(s.begin(), s.end()));
	std::cout << answer.size() << "\n";
	for(auto x: answer) {
		std::cout << x << "\n";
	}
	return 0;
}
