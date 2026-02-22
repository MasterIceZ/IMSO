#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

const int MxN = 100010;

std::vector<int> adj[MxN];
int dist[MxN], static_queue[MxN], q_idx = 0, parent[MxN];
std::bitset<MxN> visited, in_longest_path;

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, m, k;
	std::cin >> n >> m >> k;
	for(int i=1, u, v; i<=m; ++i) {
		std::cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	
	memset(dist, -1, sizeof dist);
	dist[1] = 0;
	static_queue[q_idx++] = 1;
	for(int i=0; i<q_idx; ++i) {
		int u = static_queue[i];
		for(auto v: adj[u]) {
			if(dist[v] == -1) {
				dist[v] = dist[u] + 1;
				static_queue[q_idx++] = v;
			}
		}
	}
	std::cout << "DONE 1\n";

	int furthest = static_queue[n - 1];
	std::cout << furthest << "\n";
	q_idx = 0;
	visited[furthest] = true;
	static_queue[q_idx++] = furthest;
	for(int i=0; i<q_idx; ++i) {
		int u = static_queue[i];
		for(auto v: adj[u]) {
			if(!visited[v]) {
				visited[v] = true;
				parent[v] = u;
				static_queue[q_idx++] = v;
			}
		}
	}

	std::vector<int> longest_path;
	int cur = static_queue[n - 1];
	while(cur != 0) {
		longest_path.emplace_back(cur);
		cur = parent[cur];
		in_longest_path[cur] = true;
	}

	std::vector<int> answer = longest_path;
	visited = 0;
	for(auto cur: longest_path) {
		q_idx = 0;
		visited[cur] = true;
		static_queue[q_idx++] = cur;
		for(int i=0; i<q_idx; ++i) {
			int u = static_queue[i];
			for(auto v: adj[u]) {
				answer.emplace_back(v);
				visited[v] = true;
				static_queue[q_idx++] = v;
			}
		}
	}
	for(int i=0; i<k; ++i) {
		std::cout << answer[i] << " ";
	}
	std::cout << "\n";

	return 0;
}
