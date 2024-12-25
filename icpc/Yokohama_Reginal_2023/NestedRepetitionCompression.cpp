#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 220;

string s, dp[MxN][MxN];

string get_range(int l, int r) {
  int sz = r - l + 1;
  return s.substr(l, sz);
}

string DP(int l, int r) {
  if(l == r) {
    return to_string((char) s[l]);
  }
  if(dp[l][r] != "") {
    return dp[l][r];
  }
  int sz = r - l + 1;
  dp[l][r] = get_range(l, r);
  for(int m=l; m<r; ++m) {
    string lf = DP(l, m);
    string rg = DP(m + 1, r);
    if(lf.size() + rg.size() <= dp[l][r].size()) {
      dp[l][r] = lf + rg;
    }
  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> s;
  int n = s.size();
  s = " " + s;
  cout << DP(1, n);
  return 0;
}