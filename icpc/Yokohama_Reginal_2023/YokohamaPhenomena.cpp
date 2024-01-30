#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
ll cnt = 0ll;
string s[11];

// const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

void rec(int i, int j, int state) {
  if(state == 8) {
    cnt++;
    return ;
  }
  for(int k=0; k<4; ++k) {
    int ii = di[k] + i, jj = dj[k] + j;
    if(ii < 1 || jj < 1 || ii > n || jj > m) {
      continue;
    }
    if("YOKOHAMA"[state] == s[ii][jj]) {
      rec(ii, jj, state + 1);
    }
  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    cin >> s[i];
    s[i] = " " + s[i];
  }
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      if(s[i][j] == 'Y') {
        rec(i, j, 1);
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}