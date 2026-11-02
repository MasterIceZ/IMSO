#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

const int MxN = 200020;

struct amongus_trick {
	std::vector<int> p, sz;

	void init(int n) {
		p.resize(n + 1);
		sz.resize(n + 1, 1);
		for(int i=1; i<=n; ++i) {
			p[i] = i;
		}
	}

	inline int find_root(int u) {
		while(u != p[u]) {
			u = p[u];
		}
		return u;
	}

} dsu;

int n, m, q;
std::pair<int, int> edges[MxN];

inline void add_edge(int x) {
	dsu.add_edge(edges[x].first, edges[x].second);
}

void divide(int l, int r, int opt_l, int opt_r) {
	if(l > r) {
		return ;
	}
	int mid = (l + r) >> 1;
	
	for(int i=l; i<mid; ++i) {
		add_edge(i);
	}
	int cur_opt = opt_r;
	for(; cur_opt > mid && !dsu`:; --cur_opt) {
		add_edge(cur_opt - 1);
	}

}

int main(int argc, char *argv[]) {
	std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
	std::cin >> n >> m >> q;
	for(int i=1; i<=m; ++i) {
		std::cin >> edges[i].first >> edges[i].second;
	}
	dsu.init(2 * n);
	divide(1, m, 1, m + 1);
}
