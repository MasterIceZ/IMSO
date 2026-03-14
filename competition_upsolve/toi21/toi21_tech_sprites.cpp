#include <iostream>

struct disjoint_set_union {
  int *parent, *sz, n;

  disjoint_set_union(int n): n(n) {
    parent = (int *) calloc(n, sizeof (int));
    sz = (int *) calloc(n, sizeof (int));
    init(n);
  }
  inline void init(int n) {
    for(int i=0; i<n; ++i) {
      parent[i] = i;
      sz[i] = 1;
    }
  }
  inline int find_root(int u) {
    while(u != parent[u]) {
      u = parent[u];
    }
    return u;
  }
  inline bool unite(int u, int v) {
    int ru = find_root(u);
    int rv = find_root(v);
    if(ru == rv) {
      return false;
    }
    if(sz[ru] < sz[rv]) {
      std::swap(ru, rv);
    }
    sz[ru] += sz[rv];
    parent[rv] = ru;
    return true;
  }
};

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  disjoint_set_union dsu(n);
	std::vector<std::pair<std::pair<int, int>, int>> v;
  for(int i=1, x, y; i<=n; ++i) {
	  std::cin >> x >> y;
		v.emplace_back(std::make_pair(x, y), i);
  }
	std::sort(v.begin(), v.end());
	for(int i=1; i<=n; ++i) {

	}
  return 0;
}
