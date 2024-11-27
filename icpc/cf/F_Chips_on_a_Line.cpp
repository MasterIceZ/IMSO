#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxA = 55050;
const int MxN = 1010;
const ll MOD = 998244353ll;

ll dp[MxN][MxA], fibo[MxN];

inline ll add(ll a, ll b) {
  return (a + b) % MOD;
}

int get_base(ll v) {
  int cnt = 0;
  for(int i=32; i>=1; --i) {
    while(fibo[i] <= v) {
      v -= fibo[i];
      cnt++;
    }
  }
  return cnt;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  fibo[1] = fibo[2] = 1;
  for(int i=3; i<MxN; ++i) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
  int n, x, m;
  cin >> n >> x >> m;
  dp[0][0] = 1;
  for(int state=1; state<=x; ++state) {
    ll cur_fib = fibo[state];
    ll cur = cur_fib * n;
    for(int j=0; j<=cur; ++j) {
      for(int i=1; i<=n; ++i) {
        dp[i][j + cur_fib] = add(dp[i][j + cur_fib], dp[i - 1][j]);
      }
    }
  }
  ll res = 0ll;
  for(int i=1; i<=fibo[x] * n; ++i) {
    if(get_base(i) != m) {
      continue;
    }
    res = add(res, dp[n][i]);
  }
  cout << res << "\n";
  return 0;
}