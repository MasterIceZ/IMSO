#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 5050;

ll dp[MxN][MxN];

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  string s;
  ll k;
  cin >> s >> k;
  int n = (int) s.size();
  k -= 1ll;
  s = " " + s;
  dp[n][1] = 1ll;
  for(int i=n-1; i>=1; --i) {
    for(int j=0; j<=i; ++j) {
      if(s[i] != '(' && j > 0) {
        dp[i][j] = min(dp[i][j] + dp[i + 1][j - 1], (ll) (1e18 + 100ll));
      }
      if(s[i] != ')') {
        dp[i][j] = min(dp[i][j] + dp[i + 1][j + 1], (ll) (1e18 + 100ll));
      }
    }
  }
  int state = 0;
  for(int i=1; i<=n; ++i) {
    if(s[i] == '.') {
      if(k < dp[i + 1][state + 1]) {
        cout << "(";
        state++;
      }
      else {
        cout << ")";
        k -= dp[i + 1][state + 1];
        state--;
      }
    }
    else {
      if(s[i] == '(') {
        cout << "(";
        state++;
      }
      else {
        cout << ")";
        state--;
      }
    }
  }
  cout << "\n";
  return 0;
}