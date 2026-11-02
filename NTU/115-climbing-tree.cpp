#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>

const int MxN = 330;

std::map<std::string, int> names;
int names_idx = 0, parent[MxN];

inline int name_to_idx(std::string name) {
	if(names.count(name)) {
		return names[name];
	}
	return names[name] = ++names_idx;
}

inline std::vector<int> get_family(int x) {
	std::vector<int> fam;
	while(x != 0) {
		fam.emplace_back(x);
		x = parent[x];
	}
	return fam;
}

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	
	std::string a, b;
	while(std::cin >> a >> b) {
		if(a == "no.child" && b == "no.parent") {
			break;
		}
		int a_idx = name_to_idx(a);
		int b_idx = name_to_idx(b);

		parent[a_idx] = b_idx;
	}

	while(std::cin >> a >> b) {
		int a_idx = name_to_idx(a);
		int b_idx = name_to_idx(b);

		if(a_idx == b_idx) {
			std::cout << "no relation\n";
			continue;
		}

		std::vector<int> a_family = get_family(a_idx);
		std::vector<int> b_family = get_family(b_idx);

		int lca_a, lca_b;
		for(lca_a=(int) a_family.size()-1, lca_b=(int) b_family.size()-1; lca_a>=0 && lca_b>=0; --lca_a, --lca_b) {
			if(a_family[lca_a] != b_family[lca_b]) {
				break;
			}
		}
		lca_a++, lca_b++;

		if(lca_a == (int) a_family.size() && lca_b == (int) b_family.size()) {
			std::cout << "no relation\n";
			continue;
		}

		if(lca_a == 0) {
			for(int i=3; i<=lca_b; ++i) {
				std::cout << "great ";
			}
			if(lca_b >= 2) {
				std::cout << "grand ";
			}
			std::cout << "parent\n";
			continue;
		}

		if(lca_b == 0) {
			for(int i=3; i<=lca_a; ++i) {
				std::cout << "great ";
			}
			if(lca_a >= 2) {
				std::cout << "grand ";
			}
			std::cout << "child\n";
			continue;
		}

		if(lca_a == 1 && lca_b == 1) {
			std::cout << "sibling\n";
			continue;
		}
		
		std::cout << std::min(lca_a, lca_b) - 1 << " cousin";
		if(lca_a != lca_b) {
			std::cout << " removed " << abs(lca_a - lca_b);
		}
		std::cout << "\n";
	}

	return 0;
}
