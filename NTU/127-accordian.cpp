#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	
	std::string s;
	while(std::cin >> s) {
		if(s == "#") {
			break;
		}

		std::vector<std::vector<std::string>> piles(52);
		piles[0].emplace_back(s);
		for(int i=1; i<52; ++i) {
			std::cin >> s;
			piles[i].emplace_back(s);
		}

		bool moved = true;
		while(moved) {
			moved = false;
			for(int i=0; i<(int) piles.size(); ++i) {
				if(i >= 3 && (piles[i].back()[0] == piles[i - 3].back()[0] || piles[i].back()[1] == piles[i - 3].back()[1])) {
					piles[i - 3].emplace_back(piles[i].back());
					piles[i].pop_back();

					if(piles[i].empty()) {
						piles.erase(piles.begin() + i);
					}

					moved = true;
					break;
				}
				else if(i >= 1 && (piles[i].back()[0] == piles[i - 1].back()[0] || piles[i].back()[1] == piles[i - 1].back()[1])) {
					piles[i - 1].emplace_back(piles[i].back());
					piles[i].pop_back();

					if(piles[i].empty()) {
						piles.erase(piles.begin() + i);
					}

					moved = true;
					break;
				}
			}
		}
		
		std::cout << piles.size();
		std::cout << (piles.size() == 1 ? " pile remaining:" : " piles remaining:");
		for(auto p: piles) {
			std::cout << " " << p.size();
		}
		std::cout << "\n";
	}

	return 0;
}
