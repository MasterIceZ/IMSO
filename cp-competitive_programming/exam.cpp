#include <iostream>
#include <set>
#include <utility>

signed main(int argc, char *argv[]) {
	std::set<std::pair<int, size_t>> st;
	st.emplace(1, 0);
	st.emplace(1, 3);
	st.emplace(2, 4);
	auto it = st.lower_bound({1, 0});
	std::cout << it->first << " " << it->second << "\n";
	std::cout << "-----\n";
	while(it != st.end() && it->first == 1) {
		it = st.erase(it);
	}	
	for(auto [x, y]: st) {
		std::cout << x << " " << y << "\n";
	}
	return 0;
}
