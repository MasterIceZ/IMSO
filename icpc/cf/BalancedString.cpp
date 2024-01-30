#include <bits/stdc++.h>

using namespace std;

const int MxN = 110;

int dp[2][MxN][MxN * MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;
  cerr << "PARSE DONE!\n";
  for(int i=1; i<=n; ++i) {
    for(int cnt_0=0; cnt_0<=i; ++cnt_0) {
      for(int cnt_01=0; cnt_01<=(i - cnt_0) * cnt_0; ++cnt_01) {
        dp[i & 1][cnt_0][cnt_01] = n;
      }
    }
    for(int cnt_0=0; cnt_0<=i; ++cnt_0) {
      for(int cnt_01=0; (i - cnt_0 - 1) * cnt_0; ++cnt_01) {
        dp[i & 1][cnt_0 + 1][cnt_01] = min(dp[i & 1][cnt_0 + 1][cnt_01], dp[i & 1 ^ 1][cnt_0][cnt_01] + (s[i] == '0'));
        dp[i & 1][cnt_0][cnt_01 + cnt_0] = min(dp[i & 1][cnt_0][cnt_01 + cnt_0], dp[i & 1 ^ 1][cnt_0][cnt_01] + (s[i] == '1'));
      }
    }
  }
  int c = count(s.begin(), s.end(), '0');
  cout << dp[n & 1][c][c * (n - c) / 2] / 2 << "\n";
  return 0;
}