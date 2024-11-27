#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 2020;
const int INF = 1e9 + 100;
const int di[] = {0, -1, 1, 0};
const int dj[] = {-1, 0, 0, 1};

char s[MxN][MxN];
bool visited[MxN][MxN];
pair<int, int> border;
int n, m, sum, v[MxN], w[MxN][MxN], x[MxN][MxN], mem[MxN][MxN], cost[MxN][MxN];
vector<pair<int, int>> to_add[MxN];
vector<int> to_remove[MxN];

void dfs(int i, int j) {
  visited[i][j] = true;
  border = make_pair(min(border.first, j), max(border.second, j));
  sum += (s[i][j] - '0');
  for(int k=0; k<4; ++k) {
    int ii = i + di[k];
    int jj = j + dj[k];
    if(ii < 1 || jj < 1 || ii > n || jj > m) {
      continue;
    }
    if(visited[ii][jj] || s[ii][jj] == '.') {
      continue;
    }
    dfs(ii, jj);
  }
}

inline int get_cost(int l, int r) {
  return v[r] - x[l][r];
}

void divide(int l, int r, int opt_l, int opt_r, vector<int> &dp, vector<int> &new_dp) {
  if(l > r) {
    return ;
  }
  int mid = (l + r) >> 1;
  pair<int, int> best = make_pair(-INF, -1);
  for(int k=opt_l; k<=min(opt_r, mid); ++k) {
    best = max(best, make_pair(dp[k] + get_cost(k, mid), k));
  }
  new_dp[mid] = best.first;
  divide(l, mid - 1, opt_l, best.second, dp, new_dp);
  divide(mid + 1, r, best.second, opt_r, dp, new_dp);
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    cin >> (s[i] + 1);
  }
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      if(s[i][j] == '.' || visited[i][j]) {
        continue;
      }
      sum = 0;
      border = make_pair(j, j);
      dfs(i, j);
      mem[border.first][border.second] += sum;
    }
  }
  for(int i=1; i<=m; ++i) {
    for(int j=i; j<=m; ++j) {
      v[i] += mem[i][j];
      v[j + 1] -= mem[i][j];
    }
  }
  for(int i=1; i<=m; ++i) {
    for(int j=m; j>=1; --j) {
      w[i][j] = w[i][j + 1]  + mem[i][j];
    }
  }
  for(int i=1; i<=m; ++i) {
    for(int j=m; j>=1; --j) {
      x[i][j] = x[i - 1][j] + w[i][j];
    }
  }
  for(int i=1; i<=m; ++i) {
    v[i] += v[i - 1];
  }
  vector<int> dp(m + 1, -INF), new_dp(m + 1, -INF);
  for(int i=1; i<=m; ++i) {
    dp[i] = v[i];
  }
  cout << *max_element(dp.begin(), dp.end()) << "\n";
  for(int c=2; c<=m; ++c) {
    divide(1, m, 1, m, dp, new_dp);
    dp = new_dp;
    cout << *max_element(dp.begin(), dp.end()) << "\n";
  }
  return 0;
}