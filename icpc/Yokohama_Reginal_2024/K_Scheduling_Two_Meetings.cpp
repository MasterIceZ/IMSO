#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

string s[MxN];
int b[2][MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> s[i];
    for(int j=0; j<m; ++j) {
      if(s[i][j] == 'Y') {
        b[0][i] |= (1 << j);
      }
      else {
        b[1][i] |= (1 << j);
      }
    }
  }
  bool only_zero = true;
  for(int i=1; i<=n; ++i) {
    only_zero |= (__builtin_popcount(b[0][i]) != 0);
  }
  if(only_zero) {
    
    return 0;
  }
  return 0;
}