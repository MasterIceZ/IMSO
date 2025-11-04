#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

const int MxN = 550;
const int LG = 22;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

struct edge_t{ 
	int u, v, w;

	edge_t(int _u, int _v, int _w):
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge_t &o) const {
		return w < o.w;
	}
};

struct disjoint_set_union {
	int *p;
	
	disjoint_set_union(int n) {
		p = (int *) calloc(n, sizeof(int));
		for(int i=0; i<n; ++i) {
			p[i] = i;
		}
	}
	int find_root(int u) {
		if(u == p[u]) {
			return u;
		}
		return p[u] = find_root(p[u]);
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

int n, m, a[MxN][MxN], level[MxN * MxN];
int lift[LG][MxN * MxN], max_lift[LG][MxN * MxN];
std::vector<std::pair<int, int>> adj[MxN * MxN];

int get_idx(int x, int y) {
	return x * m + y;
}

void dfs(int u, int p, int lvl) {
	for(auto [v, w]: adj[u]) {
		if(v == p) {
			continue;
		}
		lift[0][v] = u;
		max_lift[0][v] = w;
		level[v] = lvl + 1;
		dfs(v, u, lvl + 1);
	}
}

signed main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	int q;
	std::cin >> n >> m >> q;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			std::cin >> a[i][j];
		}
	}
	std::vector<edge_t> edges;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			for(int k=0; k<4; ++k) {
				int ii = di[k] + i, jj = dj[k] + j;
				if(ii < 0 || jj < 0 || ii >= n || jj >= m) {
					continue;
				}
				edges.emplace_back(get_idx(i, j), get_idx(ii, jj), std::max(a[i][j], a[ii][jj]));
			}
		}
	}
	std::sort(edges.begin(), edges.end());
	disjoint_set_union dsu(n * m);
	for(auto [u, v, w]: edges) {
		int ru = dsu.find_root(u), rv = dsu.find_root(v);
		if(ru == rv) {
			continue;
		}
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		dsu.unite(ru, rv);
	}
	lift[0][0] = 0;
	max_lift[0][0] = -1e9 - 100;
	dfs(0, -1, 0);
	for(int s=1; s<LG; ++s) {
		for(int i=0; i<n*m; ++i) {
			lift[s][i] = lift[s - 1][lift[s - 1][i]];
			max_lift[s][i] = std::max(max_lift[s - 1][i], max_lift[s - 1][lift[s - 1][i]]);
		}
	}
	while(q--) {
		int r, c, r1, c1, r2, c2;
		std::cin >> r >> c >> r1 >> c1 >> r2 >> c2;
		int res = -1e9 - 100, u = get_idx(r - 1, c - 1), v = get_idx(r1 - 1, c1 - 1);
		bool done = false;
		if(level[u] > level[v]) {
			std::swap(u, v);
		}
		for(int s=LG-1; s>=0; --s) {
			if(level[u] > level[lift[s][v]]) {
				continue;
			}
			res = std::max(res, max_lift[s][v]);
			v = lift[s][v];
		}
		if(u == v) {
			done = true;
		}
		if(!done) {
			for(int s=LG-1; s>=0; --s) {
				if(lift[s][u] == lift[s][v]) {
					continue;
				}
				res = std::max({res, max_lift[s][u], max_lift[s][v]});
				u = lift[s][u];
				v = lift[s][v];
			}
			res = std::max({res, max_lift[0][u], max_lift[0][v]});
		}
		for(int i=r1-1; i<=r2-1; ++i) {
			for(int j=c1-1; j<=c2-1; ++j) {
				res = std::max(res, a[i][j]);
			}
		}
		std::cout << res << "\n";
	}
	return 0;
}
