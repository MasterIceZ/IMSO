#include <bits/stdc++.h>

using namespace std;

const int MxN = 55;
const int di[] = {2, 0, -2, 0};
const int dj[] = {0, 2, 0, -2};

struct bipartite_matching {
  int n, m;
  vector<vector<int>> adj;
  vector<bool> visited;
  vector<int> l, r;
  void add_edge(int u, int v) {
    adj[u].emplace_back(v);
  }
  bool try_match(int u) {
    if(visited[u]) {
      return false;
    }
    visited[u] = true;
    for(auto v: adj[u]) {
      if(r[v] != -1 && !try_match(r[v])) {
        continue;
      }
      l[u] = v;
      r[v] = u;
      return true;
    }
    return false;
  }
  int max_matching() {
    int t = 1;
    while(t--) {
      visited.resize(n, false);
      for(int i=0; i<n; ++i) {
        if(l[i] != -1) {
          continue;
        }
        t |= try_match(i);
      }
    }
    int res = 0;
    for(int i=0; i<l.size(); ++i) {
      res += (l[i] != -1);
    }
    return res;
  }
  bipartite_matching(int _n, int _m):
    n(_n), m(_m), adj(_n), visited(_n, false), l(_n, -1), r(_m, -1) {}
};

char a[MxN << 1][MxN << 1];
int n, m, idx[MxN << 1][MxN << 1];
vector<pair<int, int>> position[2];

inline bool connected(int i, int j, int ii, int jj) {
  if((a[ii][jj] - '0') % 2 != (a[i][j] - '0') % 2) {
    return false;
  }
  if(n == 2 && abs(ii - i) == 2 && a[i][j] == '4') {
    return false;
  }
  if(m == 2 && abs(jj - j) == 2 && a[i][j] == '4') {
    return false;
  }
  return true;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i=0; i<2*n-1; ++i) {
    cin >> a[i];
    for(int j=0; j<2*m-1; ++j) {
      if(a[i][j] == '.') {
        a[i][j] = '#';
      }
    }
  }
  memset(idx, -1, sizeof idx);
  for(int i=0; i<2*n-1; i+=2) {
    for(int j=0; j<2*m-1; j+=2) {
      if(a[i][j] == '3' || a[i][j] == '5' || a[i][j] == '8') {
        continue;
      }
      int k = (i + j) % 4 / 2;
      idx[i][j] = position[k].size();
      position[k].emplace_back(i, j);
    }
  }
  if(position[0].size() != position[1].size()) {
    cout << "NO\n";
    return 0;
  }
  bipartite_matching mbm((int) position[0].size(), (int) position[1].size());
  for(int i=0; i<2*n-1; i+=2) {
    for(int j=0; j<2*m-1; j+=2) {
      if((i + j) % 4 != 0 || idx[i][j] == -1) {
        continue;
      }
      for(int k=0; k<4; ++k) {
        int ii = di[k] + i, jj = dj[k] + j;
        if(ii < 0 || jj < 0 || ii >= 2 * n - 1 || jj >= 2 * m - 1) {
          continue;
        }
        if(idx[ii][jj] == -1 || !connected(i, j, ii, jj)) { 
          continue;
        }
        mbm.add_edge(idx[i][j], idx[ii][jj]);
      }
    }
  }
  if(mbm.max_matching() != (int) position[0].size()) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for(int i=0; i<position[0].size(); ++i) {
    a[(position[0][i].first + position[1][mbm.l[i]].first) >> 1][(position[0][i].second + position[1][mbm.l[i]].second) >> 1] = '.';
  }
  for(int i=0; i<2*n-1; ++i) {
    cout << a[i] << "\n";
  }
  return 0;
}