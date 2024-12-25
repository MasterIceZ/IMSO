#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 55;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

int n, m;
bool visited[MxN][MxN];
char a[MxN][MxN];

ll dfs(int i, int j) {
  visited[i][j] = true;
  if(isdigit(a[i][j])) {
    return (ll) (a[i][j] - '0');
  }
  vector<ll> v;
  for(int k=0; k<4; ++k) {
    int ii = i + di[k];
    int jj = j + dj[k];
    if(ii < 1 || jj < 1 || ii > n || jj > m) {
      continue;
    }
    if(a[ii][jj] == '.' || visited[ii][jj]) {
      continue;
    }
    v.emplace_back(dfs(ii, jj));
  }
  if(a[i][j] == '#' || a[i][j] == 'P') {
    return v[0];
  }
  if(a[i][j] == '+') {
    return v[0] + v[1];
  }
  if(a[i][j] == '-') {
    return abs(v[0] - v[1]);
  }
  if(a[i][j] == '*') {
    return v[0] * v[1];
  }
  return max(v[0], v[1]) / min(v[0], v[1]);
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> n >> m;
  pair<int, int> stp;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      cin >> a[i][j];
      if(a[i][j] == 'P') {
        stp = make_pair(i, j);
      }
    }
  }
  cout << dfs(stp.first, stp.second) << "\n";
  return 0;
}