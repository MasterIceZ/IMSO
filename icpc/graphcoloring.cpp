#include <bits/stdc++.h>

using namespace std;

const int MxN = 55;

bool edge[MxN][MxN];
int n, answer = 1e9 + 100, color[MxN];

inline bool can_go(int u) {
  for(int i=1; i<=n; ++i) {
    if(edge[u][i] && color[i] == color[u]) {
      return false;
    }
  }
  return true;
}

void try_paint(int u) {
  if(u == n + 1) {
    answer = min(answer, *max_element(color + 1, color + n + 1));
    return ;
  }
  for(int i=1; i<=n; ++i) {
    if(i > answer) {
      return ;
    }
    color[u] = i;
    if(can_go(u)) {
      try_paint(u + 1);
    }
    color[u] = 0;
  }
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int m;
  cin >> n >> m;
  for(int i=1, u, v; i<=m; ++i) {
    cin >> u >> v;
    u++, v++;
    edge[u][v] = edge[v][u] = true;
  }
  try_paint(1);
  cout << answer << "\n";
  return 0;
}