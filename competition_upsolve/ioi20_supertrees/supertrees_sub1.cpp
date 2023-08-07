#include "supertrees.h"
#include <vector>

using namespace std;

int construct(std::vector<std::vector<int>> p) {
	int n = (int) p.size();
	vector<vector<int>> building(n, vector<int> (n, 0));
	for(int i=0; i<=n-2; ++i) {
		building[i][i + 1] = 1;
		building[i + 1][i] = 1;
	}
	build(building);
	return 1;
}
