#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7ll;

struct matrix_t {
  ll a[110][110];
  matrix_t() {
    for(int i=1; i<=100; ++i) {
      for(int j=1; j<=100; ++j) {
        a[i][j] = 0ll;
      }
    }
  }
  static matrix_t indentity() {
    matrix_t r;
    for(int i=1; i<=100; ++i) {
      for(int j=1; j<=100; ++j) {
        r.a[i][j] = (i == j);
      }
    }
    return r;
  }
  matrix_t operator * (const matrix_t rhs) {
    matrix_t r;
    for(int i=1; i<=100; ++i) {
      for(int j=1; j<=100; ++j) {
        for(int k=1; k<=100; ++k) {
          ll to_add = (a[i][k] * rhs.a[k][j]) % MOD;
          r.a[i][j] = (r.a[i][j] + to_add) % MOD;
        }
      }
    }
    return r;
  }
};

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  matrix_t x, answer;
  for(int i=1, u, v; i<=m; ++i) {
    cin >> u >> v;
    x.a[u][v]++;
  }
  answer = matrix_t::indentity();
  for(; k>0; k = k / 2, x = x * x) {
    if(k % 2 == 1) {
      answer = answer * x;
    }
  }
  cout << answer.a[1][n] << "\n";
  return 0;
}