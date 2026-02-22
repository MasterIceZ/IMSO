#include <iostream>
#include <vector>

const int MxN = 100010;

std::vector<int> adj[MxN];
int tour = 0, old_idx[MxN];

void dfs(int u, int p) {
	old_idx[++tour] = u;
	for(auto v: adj[u]) {
		if(v == p) {
			continue;
		}
		dfs(v, u);
	}
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);

	int n, m, k;
	std::cin >> n >> m >> k;
	for(int i=1, u, v; i<=m; ++i) {
		std::cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);	
	}
	int stp = 0;
	for(int i=1; i<=n; ++i) {
		if((int) adj[i].size() == 1) {
			stp = i;
		}
	}

	dfs(stp, 0);
	
	for(int i=1; i<=k; ++i) {
		std::cout << old_idx[i] << " ";
	}
	std::cout << "\n";

	return 0;
}
