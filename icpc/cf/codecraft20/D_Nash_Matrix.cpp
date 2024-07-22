#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1010;
const char da[] = {'D', 'R', 'L', 'U'};
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

int n;
pair<int, int> edp[MxN][MxN];
char board[MxN][MxN];

inline bool valid(int a, int b, int x, int y) {
  return edp[a][b] == edp[x][y];
}

void dfs(int i, int j, char x) {
  if(board[i][j] != 0) {
    return ;
  }
  board[i][j] = x;
  for(int k=0; k<4; ++k) {
    int ii = di[k] + i, jj = dj[k] + j;
    if(!valid(i, j, ii, jj)) {
      continue;
    }
    dfs(ii, jj, da[k]);
  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> n;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      cin >> edp[i][j].first >> edp[i][j].second;
    }
  }
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      if(edp[i][j] == make_pair(i, j) || edp[i][j] == make_pair(-1, -1))
      dfs(i, j, edp[i][j] == make_pair(i, j) ? 'X': 0);
    }
  }
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      if(board[i][j] == 0) {
        cout << "INVALID\n";
        return 0;
      }
    }
  }
  cout << "VALID\n";
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      cout << (char) (board[i][j]);
    }
    cout << "\n";
  }
  return 0;
}