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
  disjoint_set_union dsu(100000);
  return 0;
}