#include <bits/stdc++.h>

using namespace std;

const int MxN = 300030;
const char val[] = {'L', 'R'};

int adj[MxN][2];
char a[MxN];

int dfs(int u) {
  bool gone = false;
  int current_min = 1e9 + 100;
  for(int state=0; state<=1; ++state) {
    if(adj[u][state] == 0) {
      continue;
    }
    gone = true;
    current_min = min(current_min, dfs(adj[u][state]) + (a[u] != val[state]));
  }
  return gone ? current_min : 0;
}

inline void solve() {
  int n;
  cin >> n >> (a + 1);
  for(int i=1; i<=n; ++i) {
    cin >> adj[i][0] >> adj[i][1];
  }
  cout << dfs(1);
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
}