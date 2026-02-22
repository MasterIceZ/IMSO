#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

const int MxN = 100010;

std::vector<int> adj[MxN];
int static_queue[MxN], q_idx = 0, static_vector[MxN], v_idx = 0;
std::bitset<MxN> visited;

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, m, k;
	std::cin >> n >> m >> k;
	for(int i=1, u, v; i<=m; ++i) {
		std::cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	visited[1] = true;
	static_queue[q_idx++] = 1;
	for(int i=0; i<k; ++i) {
		int u = static_queue[i];
		std::cout << u << " ";
		for(auto v: adj[u]) {
			if(!visited[v]) {
				visited[v] = true;
				static_queue[q_idx++] = v;
			}
		}
	}
	std::cout << "\n";
	return 0;
}
