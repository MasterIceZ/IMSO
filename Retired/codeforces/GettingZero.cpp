#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int MOD = 32768;
const int MxN = MOD + 10;

std::vector<int> adj[MxN];
int dist[MxN];

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	for(int i=0; i<MOD; ++i) {
		adj[(i + 1) % MOD].emplace_back(i);
		adj[(i * 2) % MOD].emplace_back(i);
	}
	memset(dist, -1, sizeof dist);
	std::queue<int> q;
	dist[0] = 0;
	q.emplace(0);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto v: adj[u]) {
			if(dist[v] != -1) {
				continue;
			}
			dist[v] = dist[u] + 1;
			q.emplace(v);
		}
	}
	int n;
	std::cin >> n;
	for(int i=1, x; i<=n; ++i) {
		std::cin >> x;
		std::cout << dist[x] << " ";
	}
	std::cout << "\n";
	return 0;
}
