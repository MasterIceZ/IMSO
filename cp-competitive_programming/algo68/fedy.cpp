#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int MxN = 200020;

struct state_t {
	int v;
	long long w;
	
	state_t(int _v, long long _w):
		v(_v), w(_w) {}

	bool operator < (const state_t& o) const {
		return w > o.w;
	}
};

std::vector<std::pair<int, long long>> adj[MxN];
long long dist[MxN], w;

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	for(int i=1, u, v; i<=m; ++i) {
		std::cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	std::priority_queue<state_t> pq;
	pq.emplace(1, dist[1] = 0ll);
	while(!pq.empty()) {
		state_t cur = pq.top();
		pq.pop();
		for(auto x: adj[cur.v]) {
			long long nxt = cur.w + x.second;
			if(dist[x.first] > nxt) {
				pq.emplace(x.first, dist[x.first] = nxt);
			}
		}
	}
	long long mx = *std::max_element(dist + 1, dist + n + 1);
	for(int i=2; i<=n; ++i) {
		std::cout << mx - dist[i] << "\n";
	}
	return 0;
}
