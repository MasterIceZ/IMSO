#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>

struct edge_t {
	int u, v;
	long long w;

	bool operator < (const edge_t& o) const {
		return w < o.w;
	}

	edge_t(int _u, int _v, long long _w):
		u(_u), v(_v), w(_w) {}
};

struct disjoint_set_union {
	int *p;
	
	disjoint_set_union(int n) {
		p = (int *) calloc(n, sizeof(n));
		std::iota(p, p + n, 0);
	}

	int find_root(int u) {
		return p[u] == u ? u : p[u] = find_root(p[u]);
	}

	bool unite(int u, int v) {
		int ru = find_root(u), rv = find_root(v);
		if(ru == rv) {
			return false;
		}
		p[ru] = rv;
		return true;
	}
};

long long u, w, answer = 0ll;

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int n, m, k;
	std::cin >> n >> m >> u >> k;
	std::vector<edge_t> edges;
	for(int i=1, u, v; i<=m; ++i) {
		std::cin >> u >> v >> w;
		edges.emplace_back(--u, --v, w);
	}
	int component_count = n;
	disjoint_set_union dsu(n);
	std::sort(edges.begin(), edges.end());
	for(auto edge: edges) {
		if(!dsu.unite(edge.u, edge.v)) {
			continue;
		}
		answer += edge.w;
		if(--component_count <= k) {
			break;
		}
	}
	std::cout << answer * u << "\n";
	return 0;
}
