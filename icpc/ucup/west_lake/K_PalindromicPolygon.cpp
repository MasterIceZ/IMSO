#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 550;
const ll INF = 1e18 + 100ll;

int v[MxN << 1];
pair<ll, ll> p[MxN << 1];
ll dp[MxN << 1][MxN << 1], dp2[MxN << 1][MxN << 1];

ll cross(pair<ll, ll> u, pair<ll, ll> v) {
  return u.first * v.second - v.first * u.second;
}

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> v[i];
    v[i + n] = v[i];
  }
  for(int i=1; i<=n; ++i) {
    cin >> p[i].first >> p[i].second;
    p[i + n] = p[i];
  }
  for(int i=1; i<=2*n; ++i) {
    for(int j=1; j<=2*n; ++j) {
      dp[i][j] = -INF;
      dp2[i][j] = -INF;
      if(i < j && v[i] == v[j]) {
        dp2[i][j] = cross(p[i], p[j]);
      }
    }
  }
  for(int i=1; i<=2*n; ++i) {
    dp2[i][i] = 0ll;
  }
  ll answer = 0ll;
  for(int sz=1; sz<=n; ++sz) {
    for(int l=1; l+sz-1<=2*n; ++l) {
      int r = l + sz - 1;
      answer = max(answer, dp2[l][r] + cross(p[r], p[l]));
      for(int m=1; m<l; ++m) {
        dp[m][r] = max(dp[m][r], cross(p[m], p[l]) + dp2[l][r]);
      }
      for(int m=r+1; m<=2*n; ++m) {
        if(v[m] != v[l]) {
          continue;
        }
        dp2[l][m] = max(dp2[l][m], dp[l][r] + cross(p[r], p[m]));
      }
    }
  }
  cout << answer << "\n";
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