#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7ll;

struct matrix_t {
  ll a[3][3];
  matrix_t() {
    for(int i=1; i<=2; ++i) {
      for(int j=1; j<=2; ++j) {
        a[i][j] = 0ll;
      }
    }
  }
  static matrix_t indentity() {
    matrix_t r;
    for(int i=1; i<=2; ++i) {
      for(int j=1; j<=2; ++j) {
        r.a[i][j] = (i == j);
      }
    }
    return r;
  }
  matrix_t operator * (const matrix_t rhs) {
    matrix_t r;
    for(int i=1; i<=2; ++i) {
      for(int j=1; j<=2; ++j) {
        for(int k=1; k<=2; ++k) {
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
  ll n;
  cin >> n;
  matrix_t x, answer, t;
  x.a[1][1] = 1; x.a[1][2] = 1;
  x.a[2][1] = 1; x.a[2][2] = 0;
  answer = matrix_t::indentity();
  for(; n>0ll; n = (n / 2ll), x = x * x) {
    if(n & 1ll) {
      answer = x * answer;
    }
  }
  t.a[1][1] = 1;
  t.a[1][2] = 0;
  answer = answer * t;
  cout << answer.a[2][1] << "\n";
  return 0;
}