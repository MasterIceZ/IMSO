#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int a[MxN], qxor[MxN];
string s;

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    qxor[i] = qxor[i - 1] ^ a[i];
  }
  cin >> s;
  s = " " + s;
  int state = 0;
  for(int i=1; i<=n; ++i) {
    if(s[i] == '1') {
      state ^= a[i];
    }
  }
  int q;
  cin >> q;
  while(q--) {
    int o;
    cin >> o;
    if(o == 1) {
      int l, r;
      cin >> l >> r;
      state ^= (qxor[r] ^ qxor[l - 1]);
    }
    else {
      int g;
      cin >> g;
      if(g == 0) {
        cout << (state ^ qxor[n]);
      }
      else {
        cout << state;
      }
      cout << " ";
    }
  }
  cout << "\n";
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