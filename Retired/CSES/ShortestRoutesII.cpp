#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 550;

ll fw[MxN][MxN], w;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  memset(fw, 0x3f, sizeof fw);
  for(int i=1; i<=n; ++i) {
    fw[i][i] = 0;
  }
  for(int i=1, u, v; i<=m; ++i) {
    cin >> u >> v >> w;
    fw[u][v] = fw[v][u] = min(fw[v][u], w);
  }
  for(int k=1; k<=n; ++k) {
    for(int i=1; i<=n; ++i) {
      for(int j=1; j<=n; ++j) {
        fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
      }
    }
  }
  while(q--) {
    int u, v;
    cin >> u >> v;
    cout << (fw[u][v] >= 1e18 + 100ll ? -1ll: fw[u][v]) << "\n";
  }
  return 0;
}