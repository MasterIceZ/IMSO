#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  while(true) {
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0) {
      break;
    }
    vector<vector<char>> a(n + 1, vector<char> (m + 1));
    vector<vector<int>> dist(n + 1, vector<int> (m + 1, -1));
    for(int i=1; i<=n; ++i) {
      for(int j=1; j<=m; ++j) {
        cin >> a[i][j];
      }
    }
    deque<pair<int, int>> dq;
    for(int i=1; i<=n; ++i) {
      if(a[i][m] == '#') {
        dist[i][m] = 0;
        dq.emplace_front(i, m);
      }
    }
    for(int j=1; j<=m-1; ++j) {
      if(a[1][j] == '#') {
        dist[1][j] = 0;
        dq.emplace_front(1, j);
      }
    }
    for(int i=1; i<=n; ++i) {
      if(a[i][m] == '.') {
        dist[i][m] = 1;
        dq.emplace_back(i, m);
      }
    }
    for(int j=1; j<=m-1; ++j) {
      if(a[1][j] == '.') {
        dist[1][j] = 1;
        dq.emplace_back(1, j);
      }
    }
    bool printed = false;
    while(!dq.empty()) {
      pair<int, int> now = dq.front(); dq.pop_front();
      if(now.first == n || now.second == 1) {
        cout << dist[now.first][now.second] << "\n";
        printed = true;
        break;
      }
      for(int k=0; k<8; ++k) {
        int ii = di[k] + now.first;
        int jj = dj[k] + now.second;
        if(ii < 1 || jj < 1 || ii > n || jj > m) {
          continue;
        }
        if(a[ii][jj] == '@' || dist[ii][jj] != -1) {
          continue;
        }
        if(a[ii][jj] == '#') {
          dist[ii][jj] = dist[now.first][now.second];
          dq.emplace_front(ii, jj);
        }
        if(a[ii][jj] == '.') {
          dist[ii][jj] = dist[now.first][now.second] + 1;
          dq.emplace_back(ii, jj);
        }
      }
    }
    if(!printed) {
      cout << "-1\n";
    }
  }
  return 0;
}