// model solution Hydrolyzed~

#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

struct online_bipartite {
  pair<int, int> parent[MxN];
  int rnk[MxN];
  bool bipartite[MxN];
  
  pair<int, int> find_root(int u) {
    if(u != parent[u].first) {
      int par = parent[u].second;
      parent[u] = find_root(parent[u].first);
      parent[u].second ^= par;
    }
    return parent[u];
  }

  void add_edge(int u, int v) {
    pair<int, int> root_u = find_root(u);
    pair<int, int> root_v = find_root(v);
    if(root_u.first == root_v.first) {
      if(root_u.second == root_v.second) {
        bipartite[root_u.first] = false;
      }
    }
    else {
      if(rnk[root_u.first] < rnk[root_v.first]) {
        swap(root_u.first, root_v.first);
      }
      parent[root_v.first] = make_pair(root_u.first, root_v.second ^ root_u.second ^ 1);
      bipartite[root_u.first] &= bipartite[root_v.first];
      if(rnk[root_u.first] == rnk[root_v.first]) {
        rnk[root_u.first] = rnk[root_u.first] + 1;
      }
    }
  }

  bool check(int u) {
    return bipartite[find_root(u).first];
  }

  online_bipartite() {
    for(int i=1; i<MxN; ++i) {
      parent[i] = make_pair(i, 0);
      rnk[i] = 0;
      bipartite[i] = true;
    }
  }
} bc;

inline string yes_no(bool ok) {
  return ok ? "Yes": "No";
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, q, u, v;
  cin >> n >> q;
  while(q--) {
    cin >> u >> v;
    bc.add_edge(u, v);
    cout << yes_no(bc.check(u)) << "\n";
  }
  return 0;
}