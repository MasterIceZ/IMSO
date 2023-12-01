#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

struct disjoint_set {
  int parent[MxN], rnk[MxN];
  int find_root(int u) {
    if(u == parent[u]) {
      return u;
    }
    int prnt = find_root(parent[u]);
    rnk[u] = rnk[parent[u]] - 1;
    return prnt;
  }
  disjoint_set() {
    for(int i=1; i<MxN; ++i) {
      parent[i] = i;
      rnk[i] = 1;
    }
  }
} dsu;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, q, t, x, y, a;
  cin >> n >> q;
  while(q--) {
    cin >> t;
    if(t == 1) {
      cin >> x >> y >> a;
    }
  }
  return 0;
}