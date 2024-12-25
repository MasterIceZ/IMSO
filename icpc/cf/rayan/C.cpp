#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1010;
const int di[] = {-1, 0, 0, 1}, dj[] = {0, -1, 1, 0};

string s[MxN];
int n, m, p[MxN * MxN], out;

int fr(int u) {
  return u == p[u] ? u: p[u] = fr(p[u]);
}

int getId(int r, int c) {
  if (r >= n || r < 0 || c >= m || c < 0) {
    return out;
  }
  return r * m + c;
}

void unite(int r1, int c1, int r2, int c2) {
  int ra = fr(getId(r1, c1)), rb = fr(getId(r2, c2));
  p[ra] = rb;
}

inline void solve() {
  cin >> n >> m;
  for(int i=0; i<n; ++i) {
    cin >> s[i];
  }
  for(int i=0; i<=n*m; ++i) {
    p[i] = i;
  }
  out = n * m;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      if(s[i][j] == '?') {
        continue;
      }
      if(s[i][j] == 'U') {
        unite(i, j, i - 1, j);
      }
      else if(s[i][j] == 'D') {
        unite(i, j, i + 1, j);
      }
      else if(s[i][j] == 'L') {
        unite(i, j, i, j - 1);
      }
      else {
        unite(i, j, i, j + 1);
      }
    }
  }
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      if(s[i][j] != '?') {
        continue;
      }
      bool done = false;
      for(int k=0; k<4; ++k) {
        int ii = di[k] + i, jj = dj[k] + j;
        int rx = fr(getId(ii, jj));
        if(rx == fr(out) || ii < 0 || jj < 0 || ii >= n || jj >= m) {
          continue;
        }
        unite(i, j, ii, jj);
        done = true;
      }
      if(!done) {
        // cerr << "X: " << i << " " << j << "\n";
        p[fr(getId(i, j))] = fr(out);
      }
    }
  }
  // cerr << "\n";
  int cnt = 0;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      // cerr << "D: " << i << " " << j << " " << fr(getId(i, j)) << "\n";
      cnt += (fr(getId(i, j)) != fr(out));
    }
  }
  cout << cnt << "\n";
  return ;
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