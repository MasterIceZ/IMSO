#include "supertrees.h"
#include <vector>
#include <bitset>

using namespace std;

const int MxN = 1010;

bitset<MxN> done, in_tree;
vector<int> adj;

int construct(std::vector<std::vector<int>> p) {
	int n = (int) p.size();
	vector<vector<int>> building(n, vector<int> (n, 0));
	for(int i=0; i<=n-1; ++i) {
		if(done[i]) {
			continue;
		}
		adj.clear();
		for(int j=0; j<=n-1; ++j) {
			if(p[i][j] == 0) {
				continue;
			}
			adj.emplace_back(j);
			in_tree[j] = true;
		}
		for(auto from: adj) {
			for(int to=0; to<=n-1; ++to) {
				if((p[from][to] == 1 && !in_tree[to]) 
				|| (p[from][to] == 0 && in_tree[to])) {
					return 0;
				}
			}
		}
		for(auto x: adj) {
			in_tree[x] = false;
			done[x] = true;
		}
		for(int j=1; j<=(int)adj.size()-1; ++j) {
			building[adj[j-1]][adj[j]] = building[adj[j]][adj[j-1]] = 1;
		}
	}
	build(building);
	return 1;
}
