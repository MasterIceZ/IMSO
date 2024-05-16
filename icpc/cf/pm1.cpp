#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 550;

int a[4][MxN];

struct SAT {
  vector<vector<int>> adj, rev;
  vector<int> comp;
  int n;

  SAT(int _n): n(_n) {
    adj.resize(2 * n);
    rev.resize(2 * n);
  }
  void dfs(int u, int p) {

  }
  void dfs_2(int u, int p) {

  }
  void do_scc() {
    
  }
  void add(int clause_a, bool state_a, int clause_b, bool state_b) {
  }
  bool solve() {
    do_scc();
    for(int i=1; i<=n; ++i) {
      if(comp[2 * i] == comp[2 * i + 1]) {
        return false;
      }
    }
    return true;
  }
};

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=3; ++i) {
    for(int j=1; j<=n; ++j) {
      cin >> a[i][j];
    }
  }
  SAT sat(n + 1);
  for(int i=1; i<=n; ++i) {
    for(int state=1; state<=3; ++state) {
      int nxt_state = (state + 1) % 3 + 1;
      sat.add(abs(a[state][i]), a[state][i] > 0, abs(a[nxt_state][i]), a[nxt_state][i] > 0);
    }
  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}