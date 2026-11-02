#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

const int MxN = 2020;

struct edge_t {
	int u, v;
	long long w;
	
	edge_t(int _u, int _v, long long _w):
		u(_u), v(_v), w(_w) {}
};

long long dist[MxN], checker[MxN], w;

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, m, s, t;
	std::cin >> n >> m >> s >> t;
	std::vector<edge_t> edges;
	for(int i=1, u, v; i<=m; ++i) {
		std::cin >> u >> v >> w;
		edges.emplace_back(u, v, -w);
	}
	memset(dist, 0x3f, sizeof dist);
	dist[s] = 0;
	for(int r=2; r<=n; ++r) {
		for(auto e: edges) {
			dist[e.v] = std::min(dist[e.v], dist[e.u] + e.w);
		}
	}
	memcpy(checker, dist, sizeof dist);
	for(auto e: edges) {
		dist[e.v] = std::min(dist[e.v], dist[e.u] + e.w);
	}
	if(checker[t] != dist[t]) {
		std::cout << "INFINITY\n";
	}
	else {
		std::cout << -dist[t] << "\n";
	}
	return 0;
}
